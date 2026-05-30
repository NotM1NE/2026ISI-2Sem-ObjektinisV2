#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>

#include "../include/main.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::runtime_error;
using std::string;

int main()
{
    ReadFile("input.txt");
    return 0;
}

void ReadFile(string fileName)
{
    ifstream inputFile("../Data/" + fileName);
    if (!inputFile.is_open())
        throw runtime_error("Klaida: failas nerastas arba nepavyko atidaryti" + fileName);

    cout << "Failas " << fileName << endl;
    auto lineNumbers = GetLineNumber(inputFile);

    cout << "Eiluciu skaicius: " << lineNumbers.size() << endl;

    for (const auto &line : lineNumbers)
    {
        cout << line.first << ": " << line.second << endl;
    }

    inputFile.close();
}

map<int, string> GetLineNumber(ifstream &inputFile)
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

string CleanWord(string word)
{
    string cleanedWord;

    for(char symbol : word)
    {
        unsigned char currentSymbol = static_cast<unsigned char>(symbol);
        
        bool isLetterOrNumber = std::isalnum(currentSymbol);

        if(isLetterOrNumber)
        {
            char lowerCaseSymbol = std::tolower(currentSymbol);
            cleanedWord += lowerCaseSymbol;
        }
    }

    return cleanedWord;
}