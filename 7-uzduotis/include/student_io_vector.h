#ifndef STUDENT_IO_H_VECTOR
#define STUDENT_IO_H_VECTOR

#include "student.h"
#include <string>
#include <vector>

using std::vector;
using std::string;


void inputas(vector<Studentas> &grupe);
void outputas(vector<Studentas> grupe);

void fileRead(vector<Studentas> &grupe, string file_name);
void fileTest(vector<Studentas> &grupe, string file_name, int &testKiekis);

void sortByUser(vector<Studentas> &grupe, int temp);

void duomenuIrasymasFaile(vector<Studentas> &grupe, int temp, string fileName);
void duomenuIrasymasKonsole(vector<Studentas> &grupe, int temp);

bool containsDigit(const string &str);
void GenerateStudentsFile(int n);

void SplitStudentsStrategy1(const vector<Studentas> &grupe, vector<Studentas> &failed, vector<Studentas> &passed);
void SplitStudentsStrategy2(vector<Studentas> &grupe, vector<Studentas> &failed);
void SplitStudentsStrategy3(vector<Studentas> &grupe, vector<Studentas> &failed);

int getSortChoice(int temp);

void benchmarkProcessingFile(int n, int testKiekis, int strategy);

#endif