// formatType.cpp

#include <format>
#include <iostream>

int main() {

    int num{2020};

    std::cout << "default:     " << std::format("{:}", num) << '\n';
    std::cout << "decimal:     " << std::format("{:d}", num) << '\n';
    std::cout << "binary:      " << std::format("{:b}", num) << '\n';
    std::cout << "octal:       " << std::format("{:o}", num) << '\n';
    std::cout << "hexadecimal: " << std::format("{:x}", num) << '\n';

}