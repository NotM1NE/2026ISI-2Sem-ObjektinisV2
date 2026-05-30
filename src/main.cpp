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

#include "../include/main.h"

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

int main()
{
    auto lines = ReadFile("input.txt");
    auto words = CountWords(lines);
    WriteWordstoFile(words, "cross_reference.txt");
    WriteWordCountToFile(words, "word_count.txt");

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

vector<string> GetWordsFromLine(string line)
{
    vector<string> words;
    string word, cleanedWord;

    stringstream lineStream(line);

    while (lineStream >> word)
    {
        cleanedWord = CleanWord(word);

        if (!cleanedWord.empty())
            words.push_back(cleanedWord);
    }

    return words;
}

string CleanWord(string word)
{
    string cleanedWord;

    for (char symbol : word)
    {
        unsigned char currentSymbol = static_cast<unsigned char>(symbol);

        bool isPunctuation = std::ispunct(currentSymbol);

        if (!isPunctuation)
        {
            char lowerCaseSymbol = std::tolower(currentSymbol);
            cleanedWord += lowerCaseSymbol;
        }
    }

    return cleanedWord;
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

bool IsValidUrl(string url, const set<string>& tlds)
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
    string result;

    for (char symbol : text)
    {
        unsigned char currentSymbol = static_cast<unsigned char>(symbol);
        result += std::tolower(currentSymbol);
    }

    return result;
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