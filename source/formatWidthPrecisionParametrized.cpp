// formatWidthPrecisionParametrized.cpp

#include <format>
#include <iostream>

int main() {

    std::cout << '\n';

    double doub = 123.456789;

    std::cout << std::format("{:}\n", doub);                          

    std::cout << '\n';

    for (auto precision: {3, 5, 7, 9}) {
       std::cout << std::format("{:.{}}\n", doub, precision);         
    }

    std::cout << '\n';

    int width = 10;
    for (auto precision: {3, 5, 7, 9}) {
       std::cout << std::format("{:{}.{}}\n", doub, width, precision);  
    }
    
    std::cout << '\n';

}