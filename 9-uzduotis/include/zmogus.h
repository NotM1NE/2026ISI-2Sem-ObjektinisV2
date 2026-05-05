#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

using std::string;

class Zmogus
{
protected:
    string _vardas;
    string _pavarde;

public:
    Zmogus() {}
    Zmogus(const string &vardas, const string &pavarde)
        : _vardas(vardas), _pavarde(pavarde) {}

    virtual ~Zmogus() {}

    virtual void spausdinti() const = 0; //dont get it

    inline const string vardas() const { return _vardas; }
    inline const string pavarde() const { return _pavarde; }

    void SetVardas(const string &vardas) { _vardas = vardas; }
    void SetPavarde(const string &pavarde) { _pavarde = pavarde; }
};

#endif