#include "student.h"
#include <algorithm>

using std::sort;

void MedVidSkaciavimas(Studentas &A, int sum)
{
    int length = A.paz.size();
    if (length == 0)
    {
        A.med = A.egz * 0.6;
        A.vid = A.med;
        return;
    }
    sort(A.paz.begin(), A.paz.end());
    if (length % 2 == 0)
        A.med = (A.paz[length / 2 - 1] + A.paz[length / 2]) / 2.0 * 0.4 + A.egz * 0.6;
    else
        A.med = A.paz[length / 2] * 0.4 + A.egz * 0.6;
    A.vid = sum * 1.0 / (length * 1.0) * 0.4 + A.egz * 0.6;
}