#include "student_io_deque.h"
#include "utils.h"
#include "timer.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::getline;
using std::ifstream;
using std::left;
using std::numeric_limits;
using std::ofstream;
using std::right;
using std::setprecision;
using std::setw;
using std::sort;
using std::streamsize;
using std::string;
using std::stringstream;

void outputas(deque<Studentas> grupe)
{
    int temp, t;
    cout << "Pasirinkite norimu formatu isvesti duomenis" << endl;
    cout << "1 - isvesti tik Vidurki\n2 - isvesti tik Mediana\n3 - isvesti ir Vidurki ir Mediana\n";
    intInput(temp);
    int sortChoice = getSortChoice(temp);
    sortByUser(grupe, sortChoice);
    cout << "Pasirinkite norima buda isvesti duomenis" << endl;
    cout << "1 - isvesti i konsole\n2 - isvesti i faila\n";
    intInput(t);
    switch (t)
    {
    case 1:
        duomenuIrasymasKonsole(grupe, sortChoice);
        break;
    case 2:
    {
        deque<Studentas> failed, passed;
        SplitStudentsStrategy1(grupe, failed, passed);
        grupe.clear();

        sortByUser(failed, sortChoice);
        sortByUser(passed, sortChoice);

        duomenuIrasymasFaile(failed, sortChoice, "failed.txt");
        duomenuIrasymasFaile(passed, sortChoice, "passed.txt");

        cout << "Studentai isskirti i dvi grupes ir isvesti i failus." << endl;
        break;
    }
    default:
        break;
    }
}
void inputas(deque<Studentas> &grupe)
{
    srand(time(NULL));
    Studentas A;

    while (true)
    {
        int t = 0;
        cout << "Pasirinkite norima buda ivesti duomenis" << endl;
        cout << "1 - ranka\n2 - generuoti tik pazymius\n3 - generuoti studentu vardus, pavardes ir pazymius\n4 - nuskaityti is failo\n5 - generuoti studentu sarasa\n6 - paleisti testa\n7 - baigti darba\n";
        intInput(t);
        if (t == 1)
        {
            while (true)
            {
                cout << "Iveskite 0, kad baigti ivedinet duomenis" << endl;
                cout << "Iveskite varda ir pavarde: ";
                cin >> A.vardas;
                if (A.vardas == "0")
                    break;
                cin >> A.pavarde;
                char c = cin.peek(); // patikriname ar yra papildomu simboliu/zodziu
                if (c != '\n')       // jeigu ne eilutes pabaiga, vadinasi yra papildomu simboliu/zodziu
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ismesti likuti
                    cout << "Iveskite tik 2 zodzius (varda ir pavarde).\n";
                    continue;
                }

                cout << "Iveskite semestro ivercius. Kai baigsite iveskite 0" << endl;
                int sum = 0;
                int temp = -2;
                int i = 1;
                while (true)
                {
                    cout << "Iveskite " << i << " pazymi: ";
                    intInput(temp);
                    if (temp < 0 || temp > 10)
                    {
                        cout << "Pazymys turi buti tarp 1 ir 10. Bandykite dar karta." << endl;
                        continue;
                    }
                    if (temp == 0)
                        break;
                    A.paz.push_back(temp);
                    sum += temp;
                    i++;
                }
                while (true)
                {
                    cout << "Iveskite egzamino invertinima: ";
                    intInput(temp);
                    if (temp < 1 || temp > 10)
                    {
                        cout << "Pazymys turi buti tarp 1 ir 10. Bandykite dar karta." << endl;
                        continue;
                    }
                    break;
                }
                A.egz = temp;
                MedVidSkaciavimas(A, sum);
                grupe.push_back(A);
                A.paz.clear();
            }
        }
        if (t == 2)
        {
            while (true)
            {
                cout << "Iveskite 0, kad baigti ivedinet duomenis" << endl;
                cout << "Iveskite varda ir pavarde: ";
                cin >> A.vardas;
                if (A.vardas == "0")
                    break;
                cin >> A.pavarde;
                char c = cin.peek(); // patikriname ar yra papildomu simboliu/zodziu
                if (c != '\n')       // jeigu ne eilutes pabaiga, vadinasi yra papildomu simboliu/zodziu
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ismesti likuti
                    cout << "Iveskite tik 2 zodzius (varda ir pavarde).\n";
                    continue;
                }
                int sum = 0, rand_paz;
                for (int i = 1; i <= 10; i++)
                {
                    rand_paz = rand() % 10 + 1;
                    cout << "Sugeneruotas " << i << " pazymys: " << rand_paz << endl;
                    A.paz.push_back(rand_paz);
                    sum += rand_paz;
                }
                rand_paz = rand() % 10 + 1;
                cout << "Sugeneruotas egzamino invertinimas: " << rand_paz << endl;
                A.egz = rand_paz;
                MedVidSkaciavimas(A, sum);
                grupe.push_back(A);
                A.paz.clear();
            }
        }
        if (t == 3)
        {
            for (int i = 1; i <= 10; i++)
            {
                randomVardasPavarde(A.vardas, A.pavarde);
                cout << "Sugeneruotas " << i << " vardas ir pavarde: " << A.vardas << " " << A.pavarde << endl;
                int sum = 0, rand_paz;
                for (int ii = 1; ii <= 10; ii++)
                {
                    rand_paz = rand() % 10 + 1;
                    cout << "Sugeneruotas " << ii << " pazymys: " << rand_paz << endl;
                    A.paz.push_back(rand_paz);
                    sum += rand_paz;
                }
                A.egz = rand() % 10 + 1;
                cout << "Sugeneruotas egzamino invertinimas: " << A.egz << endl;
                MedVidSkaciavimas(A, sum);
                grupe.push_back(A);
                A.paz.clear();
            }
        }
        if (t == 4)
        {
            int testKiekis = 5; // default
            double time = 0;
            cout << "Pasirinkite norima duomenu faila" << endl;
            cout << "1 - kursiokai.txt\n2 - studentai10000.txt\n3 - studentai100000.txt\n4 - studentai1000000.txt\n";
            intInput(t);
            Timer timer;
            try
            {
                switch (t)
                {
                case 1:
                    fileTest(grupe, "kursiokai.txt", testKiekis);
                    break;
                case 2:
                    fileTest(grupe, "studentai10000.txt", testKiekis);
                    break;
                case 3:
                    fileTest(grupe, "studentai100000.txt", testKiekis);
                    break;
                case 4:
                    fileTest(grupe, "studentai1000000.txt", testKiekis);
                    break;
                default:
                    break;
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                continue;
            }

            time = timer.elapsed() / testKiekis;
            cout << "Vidutinis failo nuskaitymo laikas: " << fixed << setprecision(6) << time << " sekundes." << endl;
        }
        if (t == 5)
        {
            double time = 0;
            cout << "Pasirinkite norima dydzio faila" << endl;
            cout << "1 - studentaiGen1000.txt\n2 - studentaiGen10000.txt\n3 - studentaiGen100000.txt\n4 - studentaiGen1000000.txt\n5 - studentaiGen10000000.txt\n";
            intInput(t);
            Timer timer;
            try
            {
                switch (t)
                {
                case 1:
                    GenerateStudentsFile(1000);
                    break;
                case 2:
                    GenerateStudentsFile(10000);
                    break;
                case 3:
                    GenerateStudentsFile(100000);
                    break;
                case 4:
                    GenerateStudentsFile(1000000);
                    break;
                case 5:
                    GenerateStudentsFile(10000000);
                    break;
                default:
                    break;
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                continue;
            }
            time = timer.elapsed();
            cout << "Vidutinis failo nuskaitymo laikas: " << fixed << setprecision(6) << time << " sekundes." << endl;
        }
        if (t == 6)
        {
            cout << "Pasirinkite kiek kartu norite paleisti testa" << endl;
            cout << "Pasirinkite strategija studentu isskyrimui:" << endl;
            cout << "1 - Strategija 1\n2 - Strategija 2\n3 - Strategija 3" << endl;
            int strategy;
            intInput(strategy);
            intInput(t);
            for (int n = 1000; n <= 10000000; n *= 10)
                benchmarkProcessingFile(n, t, strategy);
        }
        if (t == 7)
            break;
    }
}

void fileTest(deque<Studentas> &grupe, string file_name, int &testKiekis)
{
    cout << "Kiek kartu norite patestuoti faila: ";
    cin >> testKiekis;
    deque<Studentas> temp_grupe; // testinimui sukuriame laikina vektoriu, kad nebutu itakos originaliam grupe vektoriui, nes fileRead funkcija modifikuoja perduodama vektoriu
    fileRead(grupe, file_name);
    for (int i = 0; i < testKiekis - 1; i++)
    {
        fileRead(temp_grupe, file_name);
        temp_grupe.clear();
    }
}

void fileRead(deque<Studentas> &grupe, string file_name)
{
    grupe.clear();
    Studentas A;
    string temp;
    int balas;
    ifstream duomenys(file_name);
    if (!duomenys.is_open())
    {
        throw std::runtime_error("Klaida: failas nerastas arba nepavyko atidaryti " + file_name);
    }
    getline(duomenys, temp); // skip header
    while (duomenys >> A.vardas >> A.pavarde)
    {
        A.paz.clear();
        A.vardas.erase(std::remove_if(A.vardas.begin(), A.vardas.end(), ::isspace), A.vardas.end());
        A.pavarde.erase(std::remove_if(A.pavarde.begin(), A.pavarde.end(), ::isspace), A.pavarde.end());

        if (A.vardas.empty() || A.pavarde.empty())
            throw std::invalid_argument("Faile nera vardo arba pavardes");
        getline(duomenys, temp);
        stringstream x(temp);

        deque<int> pazymiai;
        int sum = 0;

        while (x >> balas)
        {
            if (balas < 1 || balas > 10)
                throw std::out_of_range("Klaida: netinkamas egzamino pazymys faile " + file_name + ". Pazymys turi buti tarp 1 ir 10.");
            pazymiai.push_back(balas);
        }
        if (pazymiai.empty())
            throw std::invalid_argument("Faile nera pazymiu");

        A.egz = pazymiai.back();
        pazymiai.pop_back();
        for (int paz : pazymiai)
        {
            A.paz.push_back(paz);
            sum += paz;
        }

        MedVidSkaciavimas(A, sum);
        grupe.push_back(A);
    }
    duomenys.close();
}

void sortByUser(deque<Studentas> &grupe, int temp)
{
    switch (temp)
    {
    case 1:
        sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b)
             { return a.vardas < b.vardas; });
        break;
    case 2:
        sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b)
             { return a.pavarde < b.pavarde; });
        break;
    case 3:
        sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b)
             { return a.vid > b.vid; });
        break;
    case 4:
        sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b)
             { return a.med > b.med; });
        break;
    default:
        break;
    }
}

int getSortChoice(int temp)
{
    int t;
    cout << "Pasirinkite pagal ka rikiuoti studentus" << endl;

    while (true)
    {
        if (temp == 1)
        {
            cout << "1 - pagal varda\n2 - pagal pavarde\n3 - pagal galutini (Vid.)\n";
            intInput(t);
            if (t >= 1 && t <= 3)
                return t;
        }
        else if (temp == 2)
        {
            cout << "1 - pagal varda\n2 - pagal pavarde\n3 - pagal galutini (Med.)\n";
            intInput(t);
            if (t == 1 || t == 2)
                return t;
            if (t == 3)
                return 4; // kad naudotu mediana sortinimui
        }
        else if (temp == 3)
        {
            cout << "1 - pagal varda\n2 - pagal pavarde\n3 - pagal galutini (Vid.)\n4 - pagal galutini (Med.)\n";
            intInput(t);
            if (t >= 1 && t <= 4)
                return t;
        }

        cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";
    }
}

void duomenuIrasymasFaile(deque<Studentas> &grupe, int temp, string fileName)
{
    ofstream rezultatai(fileName);
    if (rezultatai.is_open())
    {
        rezultatai << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << right << setw(20);
        if (temp == 1)
        {
            rezultatai << right << setw(20) << "Galutinis (Vid.)" << endl;
            rezultatai << left << setw(10) << "--------------------------------------------------------" << endl;
            for (auto A : grupe)
                rezultatai << left << setw(15) << A.vardas << left << setw(20) << A.pavarde << right << setw(20) << fixed << setprecision(2) << A.vid << endl;
        }
        if (temp == 2)
        {
            rezultatai << right << setw(20) << "Galutinis (Med.)" << endl;
            rezultatai << left << setw(10) << "---------------------------------------------------------" << endl;
            for (auto A : grupe)
                rezultatai << left << setw(15) << A.vardas << left << setw(20) << A.pavarde << right << setw(20) << fixed << setprecision(2) << A.med << endl;
        }
        if (temp == 3)
        {
            rezultatai << right << setw(20) << "Galutinis (Vid.)" << right << setw(20) << "Galutinis (Med.)" << endl;
            rezultatai << left << setw(10) << "---------------------------------------------------------------------------" << endl;
            for (auto A : grupe)
                rezultatai << left << setw(15) << A.vardas << left << setw(20) << A.pavarde << right << setw(20) << fixed << setprecision(2) << A.vid << right << setw(20) << A.med << endl;
        }
    }
    rezultatai.close();
}

void duomenuIrasymasKonsole(deque<Studentas> &grupe, int temp)
{
    cout << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << right << setw(20);
    if (temp == 1)
    {
        cout << right << setw(20) << "Galutinis (Vid.)" << endl;
        cout << left << setw(10) << "--------------------------------------------------------" << endl;
        for (auto A : grupe)
            cout << left << setw(15) << A.vardas << left << setw(20) << A.pavarde << right << setw(20) << fixed << setprecision(2) << A.vid << endl;
    }
    if (temp == 2)
    {
        cout << right << setw(20) << "Galutinis (Med.)" << endl;
        cout << left << setw(10) << "---------------------------------------------------------" << endl;
        for (auto A : grupe)
            cout << left << setw(15) << A.vardas << left << setw(20) << A.pavarde << right << setw(20) << fixed << setprecision(2) << A.med << endl;
    }
    if (temp == 3)
    {
        cout << right << setw(20) << "Galutinis (Vid.)" << right << setw(20) << "Galutinis (Med.)" << endl;
        cout << left << setw(10) << "---------------------------------------------------------------------------" << endl;
        for (auto A : grupe)
            cout << left << setw(15) << A.vardas << left << setw(20) << A.pavarde << right << setw(20) << fixed << setprecision(2) << A.vid << right << setw(20) << A.med << endl;
    }
}

bool containsDigit(const string &str)
{
    if (str.empty())
        return false;
    for (char c : str)
    {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

void GenerateStudentsFile(int n)
{
    srand(time(NULL));
    int ndRand = rand() % 16 + 5;
    ofstream rez("studentaiGen" + std::to_string(n) + ".txt");
    rez << left << setw(25) << "Vardas" << setw(25) << "Pavarde";
    for (int i = 1; i <= ndRand; i++)
        rez << setw(10) << ("ND" + std::to_string(i));

    rez << setw(10) << "Egz." << endl;

    for (int i = 1; i <= n; i++)
    {
        rez << left << setw(25) << ("Vardas" + std::to_string(i)) << setw(25) << ("Pavarde" + std::to_string(i));
        for (int j = 0; j < ndRand; j++)
        {
            int pazRand = rand() % 10 + 1;
            rez << setw(10) << pazRand;
        }
        int egzRand = rand() % 10 + 1;
        rez << setw(10) << egzRand << endl;
    }
    rez.close();
}

void SplitStudentsStrategy1(const deque<Studentas> &grupe, deque<Studentas> &failed, deque<Studentas> &passed)
{
    passed.clear();
    failed.clear();

    for (const auto &A : grupe)
    {
        if (A.vid < 5.0)
            failed.push_back(A);
        else
            passed.push_back(A);
    }
}
void SplitStudentsStrategy2(deque<Studentas> &grupe, deque<Studentas> &failed)
{
    failed.clear();
    deque<Studentas> passed;

    for (const auto &A : grupe)
    {
        if (A.vid < 5.0)
            failed.push_back(A);
        else
            passed.push_back(A);
    }
    grupe = passed;
}
void SplitStudentsStrategy3(deque<Studentas> &grupe, deque<Studentas> &failed)
{
    failed.clear();
    auto it = std::stable_partition(grupe.begin(), grupe.end(),
                                    [](const Studentas &A)
                                    {
                                        return A.vid >= 5.0;
                                    });

    for (auto iter = it; iter != grupe.end(); ++iter)
        failed.push_back(*iter);

    grupe.erase(it, grupe.end());
}

void benchmarkProcessingFile(int n, int testKiekis, int strategy)
{
    double generationTotal = 0.0;
    double readTotal = 0.0;
    double splitTotal = 0.0;
    double writeTotal = 0.0;
    double totalTotal = 0.0;

    string fileName = "studentaiGen" + std::to_string(n) + ".txt";

    for (int i = 0; i < testKiekis; i++)
    {
        deque<Studentas> grupe;
        deque<Studentas> failed;
        deque<Studentas> passed;

        Timer totalTimer;

        // 1. Generavimas
        Timer generationTimer;
        GenerateStudentsFile(n);
        generationTotal += generationTimer.elapsed();

        // 2. Skaitymas
        Timer readTimer;
        fileRead(grupe, fileName);
        readTotal += readTimer.elapsed();

        // 3. Skirstymas
        Timer splitTimer;
        if (strategy == 1)
        {
            SplitStudentsStrategy1(grupe, failed, passed);
        }
        else if (strategy == 2)
        {
            SplitStudentsStrategy2(grupe, failed);
            passed = grupe;
        }
        else if (strategy == 3)
        {
            SplitStudentsStrategy3(grupe, failed);
            passed = grupe;
        }
        splitTotal += splitTimer.elapsed();

        // 4. Rasymas
        Timer writeTimer;
        duomenuIrasymasFaile(failed, 3, "failed_" + fileName);
        duomenuIrasymasFaile(passed, 3, "passed_" + fileName);
        writeTotal += writeTimer.elapsed();

        totalTotal += totalTimer.elapsed();
    }

    cout << "\n-------------------------------" << endl;
    cout << "Failas: " << fileName << endl;
    cout << "Testu kiekis: " << testKiekis << endl;
    cout << "Vidutinis generavimo laikas: " << fixed << setprecision(6) << generationTotal / testKiekis << " s" << endl;
    cout << "Vidutinis nuskaitymo laikas: " << fixed << setprecision(6) << readTotal / testKiekis << " s" << endl;
    cout << "Vidutinis skirstymo laikas: " << fixed << setprecision(6) << splitTotal / testKiekis << " s" << endl;
    cout << "Vidutinis isvedimo laikas: " << fixed << setprecision(6) << writeTotal / testKiekis << " s" << endl;
    cout << "Vidutinis bendras laikas: " << fixed << setprecision(6) << totalTotal / testKiekis << " s" << endl;
    cout << "-------------------------------\n" << endl;
}
