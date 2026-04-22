#ifndef STUDENT_IO_H_DEQUE
#define STUDENT_IO_H_DEQUE

#include "student.h"
#include <string>
#include <deque>

using std::deque;
using std::string;


void inputas(deque<Studentas> &grupe);
void outputas(deque<Studentas> grupe);

void fileRead(deque<Studentas> &grupe, string file_name);
void fileTest(deque<Studentas> &grupe, string file_name, int &testKiekis);

void sortByUser(deque<Studentas> &grupe, int temp);

void duomenuIrasymasFaile(deque<Studentas> &grupe, int temp, string fileName);
void duomenuIrasymasKonsole(deque<Studentas> &grupe, int temp);

bool containsDigit(const string &str);
void GenerateStudentsFile(int n);
void SplitStudentsStrategy1(const deque<Studentas> &grupe, deque<Studentas> &failed, deque<Studentas> &passed);
void SplitStudentsStrategy2(deque<Studentas> &grupe, deque<Studentas> &failed);
void SplitStudentsStrategy3(deque<Studentas> &grupe, deque<Studentas> &failed);
int getSortChoice(int temp);

void benchmarkProcessingFile(int n, int testKiekis, int strategy);

#endif