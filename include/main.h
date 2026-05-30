#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <set>

using std::string;
using std::ifstream;
using std::map;
using std::vector;
using std::set;

struct WordInfo
{
    int count = 0;
    set<int> lines;
};


map<int, string> ReadFile(string fileName);
void WriteWordstoFile(const map<string, WordInfo> &words, string fileName);
void WriteWordCountToFile(const map<string, WordInfo> &words, string fileName);
void WriteUrlsToFile(const set<string>& urls, string fileName);

map<int, string> GetLines(ifstream& inputFile);
map<string, WordInfo> CountWords(const map<int, string> &lines);
set<string> FindUrls(const map<int, string> &lines, const set<string> &tlds);

vector<string> GetWordsFromLine(string line);
string CleanWord(string word);
string CleanUrl(string url);

bool IsValidUrl(string url, const set<string>& tlds);
string GetTldFromUrl(string url);
string ToLowerCase(string text);
set<string> ReadTlds(string fileName);


#endif