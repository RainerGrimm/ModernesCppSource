// undefinedBehaviour.cpp

#include <array>
#include <iostream>

int main()
{

    std::cout << std::endl;

    std::array<int, 1> myArr {}; // (0)

    int i {}; // (0)

    myArr[i] = i++; // (1)

    std::cout << i << "  " << i++ << std::endl; // (1)

    std::cout << std::endl;

    int n = ++i + i; // (1)

    std::cout << "n: " << n << std::endl;

    std::cout << std::endl;
}
