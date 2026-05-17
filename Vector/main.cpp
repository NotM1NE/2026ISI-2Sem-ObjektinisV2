#include "MyVector.h"
#include <vector>
#include <iostream>

int main()
{
    MyVector<int> v = {1, 2, 3, 4, 5};
    v.PushBack(4);
    v.Insert(1, 99);
    v.Erase(2);
    v.Resize(6, 5);
    v.ShrinkToFit();

    for (int x : v)
    {
        std::cout << x << " ";
    }

    std::cout << "\nFront: " << v.Front();
    std::cout << "\nBack: " << v.Back();
    std::cout << "\nSize: " << v.size();
    std::cout << "\nCapacity: " << v.capacity();

    MyVector<int> copy = v;
    std::cout << "\nEqual: " << (copy == v);

    return 0;
    return 0;
}