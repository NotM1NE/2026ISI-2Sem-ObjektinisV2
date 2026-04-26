#include "student.h"
#include <algorithm>
#include <iostream>

using std::sort;

Studentas::Studentas(std::istream &is)
{
    ReadStudent(is);
}

std::istream& Studentas::ReadStudent(std::istream &is)
{
    is >> _vardas >> _pavarde;
    return is;
}

void Studentas::MedIrVidSkaciavimas(int sum)
{
    int length = _paz.size();
    if (length == 0)
    {
        _med = _egz * 0.6;
        _vid = _med;
        return;
    }
    sort(_paz.begin(), _paz.end());
    if (length % 2 == 0)
        _med = (_paz[length / 2 - 1] + _paz[length / 2]) / 2.0 * 0.4 + _egz * 0.6;
    else
        _med = _paz[length / 2] * 0.4 + _egz * 0.6;
    _vid = sum * 1.0 / (length * 1.0) * 0.4 + _egz * 0.6;
}