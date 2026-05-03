#include "student.h"
#include <algorithm>
#include <iostream>
#include <utility>

using std::sort;

Studentas::Studentas(std::istream &is)
    : _vardas(), _pavarde(), _paz(), _egz(0), _vid(0.0), _med(0.0)
{
    ReadStudent(is);
}

std::istream &Studentas::ReadStudent(std::istream &is)
{
    is >> _vardas >> _pavarde;
    return is;
}

Studentas::~Studentas()
{
    _vardas.clear();
    _pavarde.clear();
    _paz.clear();
    _egz = 0;
    _vid = 0.0;
    _med = 0.0;
}

Studentas::Studentas(const Studentas &other)
    : _vardas(other._vardas),
      _pavarde(other._pavarde),
      _paz(other._paz),
      _egz(other._egz),
      _vid(other._vid),
      _med(other._med)
{
}

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

Studentas &Studentas::operator=(Studentas &&other) noexcept
{
    if (this != &other)
    {
        _vardas = std::move(other._vardas);
        _pavarde = std::move(other._pavarde);
        _paz = std::move(other._paz);
        _egz = other._egz;
        _vid = other._vid;
        _med = other._med;

        other._vardas.clear();
        other._pavarde.clear();
        other._paz.clear();
        other._egz = 0;
        other._vid = 0.0;
        other._med = 0.0;
    }

    return *this;
}

Studentas::Studentas(Studentas &&other) noexcept
    : _vardas(std::move(other._vardas)),
      _pavarde(std::move(other._pavarde)),
      _paz(std::move(other._paz)),
      _egz(other._egz),
      _vid(other._vid),
      _med(other._med)
{
    other._vardas.clear();
    other._pavarde.clear();
    other._paz.clear();
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
    os << s.vardas() << " "
       << s.pavarde() << " "
       << s.vid() << " "
       << s.med();

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
    _vid = sum * 1.0 / (length * 1.0) * 0.4 + _egz * 0.6;
}