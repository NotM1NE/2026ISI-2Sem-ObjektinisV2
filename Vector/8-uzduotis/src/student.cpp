#include "student.h"
#include <algorithm>
#include <iostream>
#include <utility>

using std::sort;
using std::cout;
using std::endl;
using std::move;

Studentas::Studentas(std::istream &is)
    : Zmogus(), _paz(), _egz(0), _vid(0.0), _med(0.0)
{
    ReadStudent(is);
}

std::istream &Studentas::ReadStudent(std::istream &is)
{
    is >> _vardas >> _pavarde;
    return is;
}

// Copy konstruktorius
Studentas::Studentas(const Studentas &other)
    : Zmogus(other._vardas, other._pavarde),
      _paz(other._paz),
      _egz(other._egz),
      _vid(other._vid),
      _med(other._med)
{
}

// Copy priskyrimo operatorius
Studentas &Studentas::operator=(const Studentas &other)
{
    if (this != &other)
    {
        _vardas = other._vardas;
        _pavarde = other._pavarde;
        _paz = other._paz;
        _egz = other._egz;
        _vid = other._vid;
        _med = other._med;
    }

    return *this;
}

// Move priskyrimo operatorius
Studentas &Studentas::operator=(Studentas &&other) noexcept
{
    if (this != &other)
    {
        _vardas = move(other._vardas);
        _pavarde = move(other._pavarde);
        _paz = move(other._paz);
        _egz = other._egz;
        _vid = other._vid;
        _med = other._med;

        other._vardas.clear();
        other._pavarde.clear();
        other._paz.Clear();
        other._egz = 0;
        other._vid = 0.0;
        other._med = 0.0;
    }

    return *this;
}

// Move konstruktorius
Studentas::Studentas(Studentas &&other) noexcept
    : Zmogus(move(other._vardas), move(other._pavarde)),
      _paz(move(other._paz)),
      _egz(other._egz),
      _vid(other._vid),
      _med(other._med)
{
    other._vardas.clear();
    other._pavarde.clear();
    other._paz.Clear();
    other._egz = 0;
    other._vid = 0.0;
    other._med = 0.0;
}

std::istream &operator>>(std::istream &is, Studentas &s)
{
    return s.ReadStudent(is);
}

std::ostream &operator<<(std::ostream &os, const Studentas &s)
{
    os << s.vardas() << " " << s.pavarde() << " " << s.vid() << " " << s.med();
    return os;
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

    _vid = sum * 1.0 / length * 0.4 + _egz * 0.6;
}

void Studentas::spausdinti() const
{
    cout << vardas() << " " << pavarde() << " " << vid() << " " << med() << endl;
}