#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

using std::vector;
using std::string;

/**
 * @file utils.h
 * @brief Pagalbiniu funkciju ir duomenu aprasymas.
 */

/**
 * @brief Vardu sarasas atsitiktiniam generavimui.
 */
extern const vector<string> vardai;

/**
 * @brief Vyrisku pavardziu sarasas atsitiktiniam generavimui.
 */
extern const vector<string> vyr_pavardes;

/**
 * @brief Moterisku pavardziu sarasas atsitiktiniam generavimui.
 */
extern const vector<string> mot_pavardes;

/**
 * @brief Nuskaito sveikaji skaiciu ir patikrina ivesti.
 * @param temp Kintamasis, i kuri irasomas nuskaitytas skaicius.
 */
void intInput(int& temp);

/**
 * @brief Sugeneruoja atsitiktini varda ir pavarde.
 * @param vardas Sugeneruotas vardas.
 * @param pavarde Sugeneruota pavarde.
 */
void randomVardasPavarde(string& vardas, string& pavarde);

#endif