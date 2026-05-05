#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

using std::string;

/**
 * @file zmogus.h
 * @brief Zmogus abstrakcios bazines klases aprasymas.
 */

/**
 * @class Zmogus
 * @brief Abstrakti bazine klase, sauganti bendrus zmogaus duomenis.
 *
 * Sia klase paveldi Studentas klase
 * Is jos negalima kurti objektu tiesiogiai
 * Zmogus klase yra abstrakti, nes turi metoda spausdinti(),
 * kuri Studentas klase turi perrasyti.
 */

class Zmogus
{
protected:
    string _vardas;  /**< Vardas */
    string _pavarde; /**< Pavarde */

public:
    /**
     * @brief Konstruktorius
     */
    Zmogus() {}
    /**
     * @brief Konstruktorius su vardu ir pavarde
     * @param vardas Zmogus vardas
     * @param pavarde Zmogus pavarde
     */
    Zmogus(const string &vardas, const string &pavarde)
        : _vardas(vardas), _pavarde(pavarde) {}
    /**
     * @brief Destruktorius
     */
    virtual ~Zmogus() {}

    virtual void spausdinti() const = 0;
    /**
     * @brief grazina Zmogaus Vardas
     * @return Zmogaus vardas
     */
    inline const string vardas() const { return _vardas; }
    /**
     * @brief grazina Zmogaus Pavarde
     * @return Zmogaus pavarde
     */
    inline const string pavarde() const { return _pavarde; }
    /**
     * @brief Iraso zmogaus varda
     * @param vardas naujas Vardas
     */
    void SetVardas(const string &vardas) { _vardas = vardas; }
    /**
     * @brief Iraso zmogaus pavarde
     * @param pavarde naujas Pavarde
     */
    void SetPavarde(const string &pavarde) { _pavarde = pavarde; }
};

#endif