// unsafeComparison.cpp

#include <iostream>

int main() {

    std::cout << std::endl;

    std::cout << std::boolalpha;

    int x = -3;
    unsigned int y = 7;

    std::cout << "-3 < 7:  " << (x < y) << std::endl;
    std::cout << "-3 <= 7: " << (x <= y) << std::endl;
    std::cout << "-3 > 7:  " << (x > y) << std::endl;
    std::cout << "-3 => 7: " << (x >= y) << std::endl;

    std::cout << std::endl;
   
}