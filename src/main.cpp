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

using std::cout;

using std::endl;
using std::getline;
using std::left;
using std::setw;

using std::codecvt_utf8;
using std::ifstream;
using std::map;
using std::ofstream;
using std::regex;
using std::runtime_error;
using std::set;
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

//----------CORE-------------

map<int, string> GetLines(ifstream &inputFile)
{
    map<int, string> lines;
    string line;
    int lineNumber = 0;

    while (getline(inputFile, line))
    {
        lineNumber++; // eilutes numeris
        lines[lineNumber] = line;
    }

    return lines;
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

map<string, int> CountNumbers(const map<int, string> &lines)
{
    map<string, int> numberCount;
    vector<string> numbers;

    for (const auto &line : lines)
    {
        numbers = GetWordsFromLine(line.second);

        for (const string &number : numbers)
        {
            if (IsNumber(number))
            {
                numberCount[number]++;
            }
        }
    }

    return numberCount;
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

        for (auto match = begin; match != end; match++)
        {
            string foundUrl = match->str();

            string cleanedUrl = CleanUrl(foundUrl);

            bool urlIsNotEmpty = !cleanedUrl.empty();
            bool urlIsValid = IsValidUrl(cleanedUrl, tlds);

            if (urlIsNotEmpty && urlIsValid)
            {
                urls.insert(cleanedUrl);
            }
        }
    }

    return urls;
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

//----------IO----------
// Input

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

set<string> ReadTlds(string fileName)
{
    ifstream inputFile("../Data/" + fileName);

    if (!inputFile.is_open())
        throw runtime_error("Klaida: nepavyko atidaryti " + fileName);

    set<string> tlds;
    string tld;

    while (inputFile >> tld)
    {
        if (!tld.empty())
        {
            tlds.insert(ToLowerCase(tld));
        }
    }

    inputFile.close();

    return tlds;
}

// Output

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

//------HELPERS-----

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

bool IsValidUrl(string url, const set<string> &tlds)
{
    string tld = GetTldFromUrl(url);

    if (tld.empty())
        return false;

    return tlds.find(tld) != tlds.end();
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