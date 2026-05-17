#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <vector>
#include "zmogus.h"

using std::string;

class Studentas : public Zmogus
{
private:
    std::vector<int> _paz;
    int _egz;
    double _vid;
    double _med;

public:
    Studentas() : Zmogus(), _paz(), _egz(0), _vid(0.0), _med(0.0) {}

    Studentas(std::istream& is);

    ~Studentas() = default;

    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);

    Studentas(Studentas&& other) noexcept;
    Studentas& operator=(Studentas&& other) noexcept;

    inline const std::vector<int>& paz() const { return _paz; }
    inline int egz() const { return _egz; }
    inline double vid() const { return _vid; }
    inline double med() const { return _med; }

    std::istream& ReadStudent(std::istream&);

    void SetEgz(int egz) { _egz = egz; }
    void SetVid(double vid) { _vid = vid; }
    void SetMed(double med) { _med = med; }

    void AddPaz(int paz) { _paz.push_back(paz); }
    void ClearPaz() { _paz.clear(); }

    void MedIrVidSkaciavimas(int sum);

    void spausdinti() const override;
};

std::istream& operator>>(std::istream& is, Studentas& s);
std::ostream& operator<<(std::ostream& os, const Studentas& s);

#endif