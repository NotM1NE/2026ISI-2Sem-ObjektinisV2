#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

using std::vector;
using std::string;


extern const vector<string> vardai;
extern const vector<string> vyr_pavardes;
extern const vector<string> mot_pavardes;

void intInput(int& temp);
void randomVardasPavarde(string& vardas, string& pavarde);

#endif