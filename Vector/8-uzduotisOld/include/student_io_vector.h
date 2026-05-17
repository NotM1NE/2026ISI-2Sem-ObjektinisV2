#ifndef STUDENT_IO_VECTOR_H
#define STUDENT_IO_VECTOR_H

#include "student.h"

#include <string>
#include <vector>

void outputas(std::vector<Studentas>& grupe);
void inputas(std::vector<Studentas>& grupe);

void fileTest(std::vector<Studentas>& grupe, std::string file_name, int& testKiekis);
void fileRead(std::vector<Studentas>& grupe, std::string file_name);

void sortByUser(std::vector<Studentas>& grupe, int temp);
int getSortChoice(int temp);

void duomenuIrasymasFaile(const std::vector<Studentas>& grupe, int temp, const std::string& fileName);
void duomenuIrasymasKonsole(std::vector<Studentas>& grupe, int temp);

bool containsDigit(const std::string& str);
void GenerateStudentsFile(int n);

void SplitStudentsStrategy1(const std::vector<Studentas>& grupe,
                            std::vector<Studentas>& failed,
                            std::vector<Studentas>& passed);

void SplitStudentsStrategy2(std::vector<Studentas>& grupe, std::vector<Studentas>& failed);
void SplitStudentsStrategy3(std::vector<Studentas>& grupe, std::vector<Studentas>& failed);

void benchmarkProcessingFile(int n, int testKiekis, int strategy);
void RuleOfFiveTestas();

#endif