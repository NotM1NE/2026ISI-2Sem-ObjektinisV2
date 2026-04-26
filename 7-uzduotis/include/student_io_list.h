#ifndef STUDENT_IO_H_LIST
#define STUDENT_IO_H_LIST

#include "student.h"
#include <string>
#include <list>

using std::string;
using std::list;

void inputas(list<Studentas> &grupe);
void outputas(list<Studentas> grupe);

void fileRead(list<Studentas> &grupe, string file_name);
void fileTest(list<Studentas> &grupe, string file_name, int &testKiekis);

void sortByUser(list<Studentas> &grupe, int temp);

void duomenuIrasymasFaile(list<Studentas> &grupe, int temp, string fileName);
void duomenuIrasymasKonsole(list<Studentas> &grupe, int temp);

bool containsDigit(const string &str);
void GenerateStudentsFile(int n);
void SplitStudentsStrategy1(const list<Studentas> &grupe, list<Studentas> &failed, list<Studentas> &passed);
void SplitStudentsStrategy2(list<Studentas> &grupe, list<Studentas> &failed);
void SplitStudentsStrategy3(list<Studentas> &grupe, list<Studentas> &failed);

int getSortChoice(int temp);

void benchmarkProcessingFile(int n, int testKiekis, int strategy);

#endif