#include "MyVector.h"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> miau;
    MyVector<int> miau2;
    miau.resize(20, 2);
    miau2.Resize(10, 5);
    for (int i = 0; i < miau.size(); i++)
    {
        std::cout << miau[i] << std::endl;
    }
    std::cout << "---------" << std::endl;
    for (int i = 0; i < miau2.size(); i++)
    {
        std::cout << miau2[i] << std::endl;
    }
    miau.shrink_to_fit();

    std::cout << miau.at(4) << std::endl;
    miau2.PushBack(6);
    std::cout << miau2.Back() << std::endl;

    // std::cout << (miau2 > miau) << std::endl;
    // std::cout << (miau2 < miau) << std::endl;
    return 0;
}