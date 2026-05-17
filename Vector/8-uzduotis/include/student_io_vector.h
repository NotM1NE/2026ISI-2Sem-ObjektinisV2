#ifndef STUDENT_IO_VECTOR_H
#define STUDENT_IO_VECTOR_H

#include "student.h"
#include "../../include/MyVector.h"

#include <string>

/**
 * @file student_io_vector.h
 * @brief Studentu ivedimo, isvedimo, failu apdorojimo ir testavimo funkcijos naudojant MyVector.
 */

/**
 * @brief Isveda studentu duomenis pasirinktu budu.
 *
 * @param grupe Studentu grupe.
 */
void outputas(MyVector<Studentas>& grupe);

/**
 * @brief Leidzia vartotojui pasirinkti duomenu ivedimo buda.
 *
 * @param grupe Studentu grupe.
 */
void inputas(MyVector<Studentas>& grupe);

/**
 * @brief Testuoja failo nuskaityma kelis kartus.
 *
 * @param grupe Studentu grupe.
 * @param file_name Failo pavadinimas.
 * @param testKiekis Testu kiekis.
 */
void fileTest(MyVector<Studentas>& grupe, std::string file_name, int& testKiekis);

/**
 * @brief Nuskaito studentu duomenis is failo.
 *
 * @param grupe Studentu grupe.
 * @param file_name Failo pavadinimas.
 */
void fileRead(MyVector<Studentas>& grupe, std::string file_name);

/**
 * @brief Surusiuoja studentus pagal vartotojo pasirinkima.
 *
 * @param grupe Studentu grupe.
 * @param temp Rusiavimo pasirinkimas.
 */
void sortByUser(MyVector<Studentas>& grupe, int temp);

/**
 * @brief Grazina vartotojo pasirinkta rusiavimo kriteriju.
 *
 * @param temp Isvedimo pasirinkimas.
 * @return Rusiavimo pasirinkimas.
 */
int getSortChoice(int temp);

/**
 * @brief Isveda studentu duomenis i faila.
 *
 * @param grupe Studentu grupe.
 * @param temp Isvedimo pasirinkimas.
 * @param fileName Rezultatu failo pavadinimas.
 */
void duomenuIrasymasFaile(const MyVector<Studentas>& grupe, int temp, const std::string& fileName);

/**
 * @brief Isveda studentu duomenis i konsole.
 *
 * @param grupe Studentu grupe.
 * @param temp Isvedimo pasirinkimas.
 */
void duomenuIrasymasKonsole(MyVector<Studentas>& grupe, int temp);

/**
 * @brief Patikrina, ar tekstas sudarytas tik is skaitmenu.
 *
 * @param str Tikrinamas tekstas.
 * @return true jei tekstas sudarytas tik is skaitmenu, false kitu atveju.
 */
bool containsDigit(const std::string& str);

/**
 * @brief Sugeneruoja studentu faila su n irasu.
 *
 * @param n Studentu skaicius.
 */
void GenerateStudentsFile(int n);

/**
 * @brief Padalina studentus i failed ir passed grupes, paliekant originalia grupe nepakeista.
 *
 * @param grupe Pradine studentu grupe.
 * @param failed Neislaike studentai.
 * @param passed Islaike studentai.
 */
void SplitStudentsStrategy1(const MyVector<Studentas>& grupe,
                            MyVector<Studentas>& failed,
                            MyVector<Studentas>& passed);

/**
 * @brief Padalina studentus i failed ir passed grupes, pakeiciant pradine grupe.
 *
 * Po funkcijos grupe paliekami tik islaike studentai.
 *
 * @param grupe Pradine studentu grupe.
 * @param failed Neislaike studentai.
 */
void SplitStudentsStrategy2(MyVector<Studentas>& grupe, MyVector<Studentas>& failed);

/**
 * @brief Padalina studentus i failed ir passed grupes naudojant stable_partition.
 *
 * Po funkcijos grupe paliekami tik islaike studentai.
 *
 * @param grupe Pradine studentu grupe.
 * @param failed Neislaike studentai.
 */
void SplitStudentsStrategy3(MyVector<Studentas>& grupe, MyVector<Studentas>& failed);

/**
 * @brief Atlieka failo generavimo, skaitymo, skirstymo ir rasymo spartos testa.
 *
 * @param n Studentu skaicius.
 * @param testKiekis Kiek kartu kartoti testa.
 * @param strategy Studentu skirstymo strategija.
 */
void benchmarkProcessingFile(int n, int testKiekis, int strategy);

/**
 * @brief Patikrina Studentas klases Rule of Five funkcijas.
 */
void RuleOfFiveTestas();

#endif