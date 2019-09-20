// formatSpecifier.cpp

#include <iostream>

int main()
{

    std::cout << std::endl;

    int num { 2011 };

    std::cout << num << "\n\n";

    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << num << std::endl;
    std::cout.setf(std::ios::dec, std::ios::basefield);
    std::cout << num << std::endl;

    std::cout << std::endl;

    std::cout << std::hex << num << std::endl;
    std::cout << std::dec << num << std::endl;

    std::cout << std::endl;
}
