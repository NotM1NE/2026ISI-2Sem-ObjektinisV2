#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <set>

using std::string;

struct WordInfo
{
    int count = 0;
    std::set<int> lines;
};
// Core
std::map<int, string> GetLines(std::ifstream& inputFile);
std::map<string, WordInfo> CountWords(const std::map<int, string> &lines);
std::vector<string> GetWordsFromLine(string line);
std::map<string, int> CountNumbers(const std::map<int, string> &lines);
std::set<string> FindUrls(const std::map<int, string> &lines, const std::set<string> &tlds);
string GetTldFromUrl(string url);

//----------IO----------
// Input

std::map<int, string> ReadFile(string fileName);
std::set<string> ReadTlds(string fileName);

// Output
void WriteWordCountToFile(const std::map<string, WordInfo> &words, string fileName);
void WriteWordstoFile(const std::map<string, WordInfo> &words, string fileName);
void WriteUrlsToFile(const std::set<string>& urls, string fileName);
void WriteNumberCountToFile(const std::map<string, int> &numbers, string fileName);

//--------HELPERS--------
bool IsUnicodePunctuation(wchar_t symbol);
bool IsValidUrl(string url, const std::set<string>& tlds);
bool IsNumber(const string &text);

string CleanUrl(string url);
string ToLowerCase(string text);
string WstringToUtf8(const std::wstring& text);

std::wstring Utf8ToWstring(const std::string& text);

#endif