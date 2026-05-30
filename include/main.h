#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <fstream>
#include <map>

using std::string;
using std::ifstream;
using std::map;

void ReadFile(string fileName);

map<int, string> GetLineNumber(ifstream& inputFile);
string CleanWord(string word);

#endif