#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Studentas
{
private:
    string _vardas;
    string _pavarde;
    vector<int> _paz;
    int _egz;
    double _vid;
    double _med;

public:
    Studentas() : _egz(0), _vid(0.0), _med(0.0) {}
    Studentas(std::istream &is);

    ~Studentas(); //destruktorius

    Studentas(const Studentas& other); //copy konstruktorius - sukuria nauja objekta
    Studentas& operator =(const Studentas& other); //copy priskyrimo konstruktorius - kopijojame egzistuojancia objekta
    Studentas(Studentas && other) noexcept; //noexcept - neturetu mesti isimciu
    Studentas& operator =(Studentas&& other) noexcept; //noexcept - neturetu mesti isimciu

    inline const string vardas() const { return _vardas; }
    inline const string pavarde() const { return _pavarde; }
    inline const vector<int> paz() const { return _paz; }
    inline int egz() const { return _egz; }
    inline double vid() const { return _vid; }
    inline double med() const { return _med; }

    std::istream &ReadStudent(std::istream&);

    void SetVardas(const string& vardas) { _vardas = vardas; }
    void SetPavarde(const string& pavarde) { _pavarde = pavarde; }
    void SetEgz(int egz) { _egz = egz; }
    void SetVid(double vid) { _vid = vid; }
    void SetMed(double med) { _med = med; }
    void AddPaz(int paz) {_paz.push_back(paz); }
    void ClearPaz() { _paz.clear(); }

    void MedIrVidSkaciavimas(int sum);
};

std::istream& operator>>(std::istream& is, Studentas& s);
std::ostream& operator<<(std::ostream& os, const Studentas& s);

#endif