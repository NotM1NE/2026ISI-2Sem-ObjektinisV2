#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <cctype>
#include <vector>
#include <sstream>
#include <set>
#include <iomanip>
#include <regex>
#include <locale>
#include <codecvt>
#include <cwctype>

#include "../include/main.h"

using std::codecvt_utf8;
using std::cout;
using std::endl;
using std::ifstream;
using std::left;
using std::map;
using std::ofstream;
using std::regex;
using std::runtime_error;
using std::set;
using std::setw;
using std::sregex_iterator;
using std::string;
using std::stringstream;
using std::vector;
using std::wstring;
using std::wstring_convert;

int main()
{
    auto lines = ReadFile("inputas.txt");
    auto words = CountWords(lines);
    auto numbers = CountNumbers(lines);
    WriteWordstoFile(words, "cross_reference.txt");
    WriteWordCountToFile(words, "word_count.txt");
    WriteNumberCountToFile(numbers, "number_count.txt");

    auto tlds = ReadTlds("tldList.txt");
    auto urls = FindUrls(lines, tlds);
    WriteUrlsToFile(urls, "urls.txt");
    return 0;
}

map<int, string> ReadFile(string fileName)
{
    ifstream inputFile("../Data/" + fileName);
    if (!inputFile.is_open())
        throw runtime_error("Klaida: failas nerastas arba nepavyko atidaryti" + fileName);

    cout << "Failas " << fileName << endl;
    auto lines = GetLines(inputFile);

    cout << "Eiluciu skaicius: " << lines.size() << endl;
    inputFile.close();

    return lines;
}

map<int, string> GetLines(ifstream &inputFile)
{
    map<int, string> lines;
    string line;
    int lineNumber = 0;

    while (std::getline(inputFile, line))
    {
        lineNumber++;
        lines[lineNumber] = line;
    }

    return lines;
}

bool IsUnicodePunctuation(wchar_t symbol)
{
    return (symbol >= 0x2000 && symbol <= 0x206F) || // general punctuation
           (symbol >= 0x2E00 && symbol <= 0x2E7F) || // supplemental punctuation
           (symbol >= 0x3000 && symbol <= 0x303F) || // CJK punctuation
           symbol == L'„' ||
           symbol == L'“' ||
           symbol == L'”' ||
           symbol == L'‘' ||
           symbol == L'’' ||
           symbol == L'«' ||
           symbol == L'»';
}

vector<string> GetWordsFromLine(string line)
{
    vector<string> words;
    wstring wideLine = Utf8ToWstring(line);
    wstring currentWord;

    for (wchar_t symbol : wideLine)
    {
        bool isAsciiLetterOrDigit =
            (symbol >= L'a' && symbol <= L'z') ||
            (symbol >= L'A' && symbol <= L'Z') ||
            (symbol >= L'0' && symbol <= L'9');

        bool isUnicodeWordSymbol =
            symbol >= 128 && !IsUnicodePunctuation(symbol);

        if (isAsciiLetterOrDigit || isUnicodeWordSymbol)
        {
            currentWord += std::towlower(symbol);
        }
        else
        {
            if (!currentWord.empty())
            {
                words.push_back(WstringToUtf8(currentWord));
                currentWord.clear();
            }
        }
    }

    if (!currentWord.empty())
    {
        words.push_back(WstringToUtf8(currentWord));
    }

    return words;
}

wstring Utf8ToWstring(const string &text)
{
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(text);
}

string WstringToUtf8(const wstring &text)
{
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(text);
}

map<string, WordInfo> CountWords(const map<int, string> &lines)
{
    map<string, WordInfo> wordCount;
    vector<string> words;

    for (const auto &line : lines)
    {
        words = GetWordsFromLine(line.second);
        for (const auto &word : words)
        {
            if (IsNumber(word))
                continue;
            if (wordCount.find(word) == wordCount.end())
            {
                wordCount[word].count = 1;
                wordCount[word].lines.insert(line.first);
            }
            else
            {
                wordCount[word].count++;
                wordCount[word].lines.insert(line.first);
            }
        }
    }

    return wordCount;
}

map<string, int> CountNumbers(const map<int, string> &lines)
{
    map<string, int> numberCount;

    for (const auto &line : lines)
    {
        vector<string> tokens = GetWordsFromLine(line.second);

        for (const string &token : tokens)
        {
            if (IsNumber(token))
            {
                numberCount[token]++;
            }
        }
    }

    return numberCount;
}

void WriteWordstoFile(const map<string, WordInfo> &words, string fileName)
{
    ofstream output("../Results/" + fileName);
    if (!output.is_open())
        throw runtime_error("Klaida: failas nerastas arba nepavyko atidaryti " + fileName);

    output << "Word\tCount\tLines" << endl;

    for (const auto &word : words)
    {
        if (word.second.count > 1)
        {
            output << word.first << "\t" << word.second.count << "\t";

            bool firstLine = true;

            for (int line : word.second.lines)
            {
                if (!firstLine)
                    output << ", ";

                output << line;
                firstLine = false;
            }

            output << endl;
        }
    }

    output.close();
}

void WriteWordCountToFile(const map<string, WordInfo> &words, string fileName)
{
    ofstream output("../Results/" + fileName);
    if (!output.is_open())
        throw runtime_error("Klaida: failas nerastas arba nepavyko atidaryti " + fileName);

    output << "Word\tCount" << endl;

    for (const auto &word : words)
        output << word.first << "\t" << word.second.count << endl;

    output.close();
}

set<string> FindUrls(const map<int, string> &lines, const set<string> &tlds)
{
    set<string> urls;

    regex urlPattern(R"((https?:\/\/)?(www\.)?[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}([\/?#][^\s]*)?)");

    for (const auto &line : lines)
    {
        string text = line.second;

        auto begin = sregex_iterator(text.begin(), text.end(), urlPattern);
        auto end = sregex_iterator();

        for (auto iterator = begin; iterator != end; iterator++)
        {
            string url = iterator->str();
            url = CleanUrl(url);

            if (!url.empty() && IsValidUrl(url, tlds))
                urls.insert(url);
        }
    }

    return urls;
}

bool IsValidUrl(string url, const set<string> &tlds)
{
    string tld = GetTldFromUrl(url);

    if (tld.empty())
        return false;

    return tlds.find(tld) != tlds.end();
}

string GetTldFromUrl(string url)
{
    string cleanedUrl = url;

    size_t protocolPosition = cleanedUrl.find("://");

    if (protocolPosition != string::npos)
        cleanedUrl = cleanedUrl.substr(protocolPosition + 3);

    size_t slashPosition = cleanedUrl.find('/');

    if (slashPosition != string::npos)
        cleanedUrl = cleanedUrl.substr(0, slashPosition);

    size_t questionPosition = cleanedUrl.find('?');

    if (questionPosition != string::npos)
        cleanedUrl = cleanedUrl.substr(0, questionPosition);

    size_t hashPosition = cleanedUrl.find('#');

    if (hashPosition != string::npos)
        cleanedUrl = cleanedUrl.substr(0, hashPosition);

    size_t lastDotPosition = cleanedUrl.rfind('.');

    if (lastDotPosition == string::npos)
        return "";

    string tld = cleanedUrl.substr(lastDotPosition + 1);

    return ToLowerCase(tld);
}

string CleanUrl(string url)
{
    while (!url.empty())
    {
        char lastSymbol = url.back();

        if (lastSymbol == '.' || lastSymbol == ',' || lastSymbol == ';' || lastSymbol == ')' || lastSymbol == ']')
            url.pop_back();
        else
            break;
    }

    return url;
}

string ToLowerCase(string text)
{
    wstring wideText = Utf8ToWstring(text);
    wstring result;

    for (wchar_t symbol : wideText)
    {
        result += std::towlower(symbol);
    }

    return WstringToUtf8(result);
}

set<string> ReadTlds(string fileName)
{
    ifstream inputFile("../Data/" + fileName);

    if (!inputFile.is_open())
        throw runtime_error("Klaida: nepavyko atidaryti " + fileName);

    set<string> tlds;
    string tld;

    while (inputFile >> tld)
    {
        if (!tld.empty() && tld[0] != '#')
        {
            tlds.insert(ToLowerCase(tld));
        }
    }

    inputFile.close();

    return tlds;
}

void WriteUrlsToFile(const set<string> &urls, string fileName)
{
    ofstream output("../Results/" + fileName);

    if (!output.is_open())
        throw runtime_error("Klaida: nepavyko sukurti arba atidaryti " + fileName);

    output << "Found URLs" << endl;

    for (const string &url : urls)
    {
        output << url << endl;
    }

    output.close();
}

bool IsNumber(const string &text)
{
    if (text.empty())
        return false;

    for (char symbol : text)
    {
        if (!std::isdigit(static_cast<unsigned char>(symbol)))
            return false;
    }

    return true;
}

void WriteNumberCountToFile(const map<string, int> &numbers, string fileName)
{
    ofstream output("../Results/" + fileName);

    if (!output.is_open())
        throw runtime_error("Klaida: nepavyko sukurti arba atidaryti " + fileName);

    output << "Number\tCount" << endl;

    for (const auto &number : numbers)
    {
        output << number.first << "\t" << number.second << endl;
    }

    output.close();
}