#include "timer.h"
#include "MyVector.h"

#include <vector>
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    int sizes[] = {1000, 10000, 100000, 1000000, 10000000, 100000000};
    cout << std::fixed << std::setprecision(6);

    cout << std::left
         << std::setw(15) << "Elementai" << " | "
         << std::setw(15) << "std::vector" << " | "
         << std::setw(15) << "MyVector" << " | "
         << std::setw(15) << "std realloc" << " | "
         << std::setw(15) << "my realloc" << " | "
         << std::setw(10) << "ratio"
         << endl;

    cout << "=================================================================================================" << endl;
    for (int sz : sizes)
    {
        int stdReallocs = 0;
        int myReallocs = 0;

        Timer timer;

        std::vector<int> v1;

        for (int i = 1; i <= sz; ++i)
        {
            if (v1.size() == v1.capacity())
                stdReallocs++;

            v1.push_back(i);
        }

        double stdTime = timer.elapsed();

        timer.reset();

        MyVector<int> v2;

        for (int i = 1; i <= sz; ++i)
        {
            if (v2.size() == v2.capacity())
                myReallocs++;

            v2.PushBack(i);
        }

        double myTime = timer.elapsed();
        double ratio = myTime / stdTime;

        cout << std::left
             << std::setw(15) << sz << " | "
             << std::setw(15) << stdTime << " | "
             << std::setw(15) << myTime << " | "
             << std::setw(15) << stdReallocs << " | "
             << std::setw(15) << myReallocs << " | "
             << std::setw(10) << ratio
             << endl;
    }

    return 0;
}