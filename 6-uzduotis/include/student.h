#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Studentas
{
    string vardas = "A", pavarde = "BB";
    vector<int> paz;
    int egz;
    double vid, med;
};

void MedVidSkaciavimas(Studentas &A, int sum);

#endif