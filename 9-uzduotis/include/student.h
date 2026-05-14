#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>
#include "zmogus.h"

using std::string;
using std::vector;

/**
 * @file student.h
 * @brief Studentas klases aprasymas.
 */

/**
 * @class Studentas
 * @brief Klase, skirta saugoti studento duomenis, paveldi Zmogus klase.
 *
 * Studentas klase saugo studento pazymius, egzamina, vidurki ir mediana
 * Ji paveldi varda ir pavarde is zmogus klases
 */

class Studentas : public Zmogus
{
private:
    vector<int> _paz; /**< Studento pazymiai */
    int _egz;         /**< Studento egzamino pazymis */
    double _vid;      /**< Studento bendras pazymiu vidurkis */
    double _med;      /**< Studento bendras pazymiu midiana */

public:
    /**
     * @brief Konstruktorius
     *
     * Sukuria tuscia studento objekta.
     * Nustato pazymius 0
     */
    Studentas() : Zmogus(), _paz(), _egz(0), _vid(0.0), _med(0.0) {}
    /**
     * @brief Konstruktorius, kuris nuskaito studento duomenis is ivesties srauto
     *
     * @param is Ivesties srautas, is kurio bus skaitomi studento duomenys
     */
    Studentas(std::istream &is);

    /**
     * @brief Destruktorius
     */
    ~Studentas() = default; // destruktorius
    /**
     * @brief Kopijavimo konstruktorius.
     * @param other Studentas objektas, is kurio kopijuojami duomenys.
     */
    Studentas(const Studentas &other); // copy konstruktorius - sukuria nauja objekta
    /**
     * @brief Kopijavimo priskyrimo operatorius.
     * @param other Studentas objektas, is kurio kopijuojami duomenys.
     * @return Nuoroda i si objekta.
     */
    Studentas &operator=(const Studentas &other); // copy priskyrimo konstruktorius - kopijojame egzistuojancia objekta
    /**
     * @brief Perkelimo konstruktorius.
     * @param other Studentas objektas, is kurio perkeliami duomenys.
     */
    Studentas(Studentas &&other) noexcept; // noexcept - neturetu mesti isimciu
    /**
     * @brief Perkelimo priskyrimo operatorius.
     * @param other Studentas objektas, is kurio perkeliami duomenys.
     * @return Nuoroda i si objekta.
     */
    Studentas &operator=(Studentas &&other) noexcept; // noexcept - neturetu mesti isimciu

    /**
     * @brief grazina Studento Pazymius
     * @return Studento pazymius vector<int>
     */
    inline const vector<int> paz() const { return _paz; }
    /**
     * @brief grazina Studento egzamino pazymi
     * @return Studento egzamino pazymis
     */
    inline int egz() const { return _egz; }
    /**
     * @brief grazina Studento pazymiu vidurki
     * @return Studento pazymiu vidurkis
     */
    inline double vid() const { return _vid; }
    /**
     * @brief grazina Studento pazymiu mediana
     * @return Studento pazymiu mediana
     */
    inline double med() const { return _med; }

    std::istream &ReadStudent(std::istream &);

    /**
     * @brief Nustato studento egzamino pazymi.
     * @param egz Egzamino pazymys.
     */
    void SetEgz(int egz) { _egz = egz; }
    /**
     * @brief Nustato galutini bala pagal vidurki.
     * @param vid Galutinis balas pagal vidurki.
     */
    void SetVid(double vid) { _vid = vid; }
    /**
     * @brief Nustato galutini bala pagal mediana.
     * @param med Galutinis balas pagal mediana.
     */
    void SetMed(double med) { _med = med; }
    /**
     * @brief Prideda viena namu darbu pazymi.
     * @param paz Namu darbu pazymys.
     */
    void AddPaz(int paz) { _paz.push_back(paz); }
    /**
     * @brief Isvalo visus namu darbu pazymius.
     */
    void ClearPaz() { _paz.clear(); }

    /**
     * @brief Apskaiciuoja galutinius balus pagal vidurki ir mediana.
     * @param sum Namu darbu pazymiu suma.
     */
    void MedIrVidSkaciavimas(int sum);

    /**
     * @brief Isveda studento duomenis.
     */
    void spausdinti() const override;
};

/**
 * @brief Ivesties operatorius studento duomenims nuskaityti.
 * @param is Ivesties srautas.
 * @param s Studentas objektas.
 * @return Ivesties srautas.
 */
std::istream& operator>>(std::istream& is, Studentas& s);

/**
 * @brief Isvesties operatorius studento duomenims isvesti.
 * @param os Isvesties srautas.
 * @param s Studentas objektas.
 * @return Isvesties srautas.
 */
std::ostream& operator<<(std::ostream& os, const Studentas& s);

#endif