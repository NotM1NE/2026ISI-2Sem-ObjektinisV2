#ifndef STUDENT_IO_H_DEQUE
#define STUDENT_IO_H_DEQUE

#include "student.h"
#include <string>
#include <deque>

using std::deque;
using std::string;

/**
 * @file student_io_deque.h
 * @brief Funkcijos darbui su Studentas objektais naudojant deque konteineri.
 */

/**
 * @brief Leidzia vartotojui ivesti arba nuskaityti studento duomenis
 * @param grupe Studentu deque konteineris
 */
void inputas(deque<Studentas> &grupe);

/**
 * @brief Leidzia vartotojui pasirinkti studentu isvedimo buda.
 * @param grupe Studentu deque konteineris
 */
void outputas(deque<Studentas>& grupe);

/**
 * @brief Nuskaito studentu duomenis is failo.
 * @param grupe Studentu deque konteineris, i kuri irasomi nuskaityti studentai.
 * @param file_name Failo pavadinimas.
 */
void fileRead(deque<Studentas> &grupe, string file_name);
/**
 * @brief Testuoja studentu nuskaityma is failo kelis kartus.
 * @param grupe Studentu deque konteineris.
 * @param file_name Failo pavadinimas.
 * @param testKiekis Testu skaicius.
 */
void fileTest(deque<Studentas> &grupe, string file_name, int &testKiekis);
/**
 * @brief Grazina vartotojo pasirinkta rikiavimo kriteriju.
 * @param temp Pasirinktas isvedimo formatas.
 * @return Rikiavimo pasirinkimo numeris.
 */
void sortByUser(deque<Studentas> &grupe, int temp);
/**
 * @brief Iraso studentu duomenis i faila.
 * @param grupe Studentu deque konteineris.
 * @param temp Isvedimo formato pasirinkimas.
 * @param fileName Failo pavadinimas.
 */
void duomenuIrasymasFaile(const deque<Studentas>& grupe, int temp, const string& fileName);
/**
 * @brief Isveda studentu duomenis i konsole.
 * @param grupe Studentu deque konteineris.
 * @param temp Isvedimo formato pasirinkimas.
 */
void duomenuIrasymasKonsole(deque<Studentas> &grupe, int temp);

/**
 * @brief Patikrina, ar eilute sudaryta tik is skaitmenu.
 * @param str Tikrinama eilute.
 * @return true, jei eilute sudaryta tik is skaitmenu, false kitu atveju.
 */
bool containsDigit(const string &str);
/**
 * @brief Sugeneruoja studentu duomenu faila.
 * @param n Studentu skaicius faile.
 */
void GenerateStudentsFile(int n);
/**
 * @brief Padalina studentus i dvi grupes: neislaikiusius ir islaikiusius.
 * @param grupe Pradine studentu grupe.
 * @param failed Neislaikiusiu studentu grupe.
 * @param passed Islaikiusiu studentu grupe.
 */
void SplitStudentsStrategy1(const deque<Studentas> &grupe, deque<Studentas> &failed, deque<Studentas> &passed);
/**
 * @brief Padalina studentus i dvi grupes, paliekant islaikiusius pradineje grupeje.
 * @param grupe Pradine studentu grupe, po funkcijos joje lieka islaike studentai.
 * @param failed Neislaikiusiu studentu grupe.
 */
void SplitStudentsStrategy2(deque<Studentas> &grupe, deque<Studentas> &failed);
/**
 * @brief Padalina studentus i dvi grupes naudojant stable_partition.
 * @param grupe Pradine studentu grupe, po funkcijos joje lieka islaike studentai.
 * @param failed Neislaikiusiu studentu grupe.
 */
void SplitStudentsStrategy3(deque<Studentas> &grupe, deque<Studentas> &failed);


/**
 * @brief Rusiuoja pagal vartotojo pasirinkta varianta.
 * @param temp Rusiavimo formato pasirinkimas.
 */
int getSortChoice(int temp);

/**
 * @brief Atlieka failo generavimo, nuskaitymo, skirstymo ir rasymo greicio testa.
 * @param n Studentu skaicius.
 * @param testKiekis Kiek kartu kartojamas testas.
 * @param strategy Studentu skirstymo strategijos numeris.
 */
void benchmarkProcessingFile(int n, int testKiekis, int strategy);

/**
 * @brief Atlieka Rule of Five demonstracini testa Studentas klasei.
 */
void RuleOfFiveTestas();

#endif