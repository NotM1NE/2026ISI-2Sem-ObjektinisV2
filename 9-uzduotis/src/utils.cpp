#include "utils.h"
#include <iostream>
#include <limits>
#include <cstdlib>

using std::cin;
using std::cout;
using std::numeric_limits;
using std::rand;
using std::streamsize;
using std::string;
using std::vector;

const vector<string> vardai = {"Jonas", "Mantas", "Tomas", "Lukas", "Karolis", "Darius", "Paulius", "Mindaugas", "Justas", "Rokas",
                               "Agne", "Ieva", "Egle", "Gabija", "Monika", "Karolina", "Viktorija", "Emilija", "Justina", "Greta"};

const vector<string> vyr_pavardes = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Zukauskas", "Butkus", "Pocius", "Urbonas", "Mockus", "Savickas"};

const vector<string> mot_pavardes = {"Kazlauskiene", "Jankauskiene", "Petrauskiene", "Stankeviciene", "Zukauskiene", "Butkiene", "Pociene", "Urboniene", "Mockiene", "Savickiene"};

void intInput(int &temp)
{
    while (true)
    {
        try
        {
            if (!(cin >> temp))
            {
                throw std::invalid_argument("Netinkamas ivestis. Bandykite dar karta.");
            }
            return;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            cout << "Netinkamas ivestis. Bandykite dar karta.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        }
    }
}

void randomVardasPavarde(string &vardas, string &pavarde)
{
    vardas = vardai[rand() % vardai.size()];
    if (!vardas.empty() && vardas.back() == 's')
        pavarde = vyr_pavardes[rand() % vyr_pavardes.size()];
    else
        pavarde = mot_pavardes[rand() % mot_pavardes.size()];
}