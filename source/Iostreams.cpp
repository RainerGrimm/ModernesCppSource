// Iostreams.cpp

#include <iostream>

int main()
{

    std::cout << std::endl;

    std::cout << "Type in your numbers(Quit with an arbitrary character): " << std::endl;

    int sum { 0 };
    int val;

    while (std::cin >> val)
        sum += val;

    std::cout << "Sum: " << sum << std::endl;

    std::cout << std::endl;
}
