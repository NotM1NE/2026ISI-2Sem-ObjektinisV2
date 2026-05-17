#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

using std::string;

extern const std::vector<string> vardai;
extern const std::vector<string> vyr_pavardes;
extern const std::vector<string> mot_pavardes;

void intInput(int& temp);
void randomVardasPavarde(string& vardas, string& pavarde);

#endif