// formatAlternate.cpp

#include <format>
#include <iostream>
 
int main() {

    std::cout << '\n';

    std::cout << std::format("{:#015}", 0x78) << '\n';
    std::cout << std::format("{:#015b}", 0x78) << '\n';
    std::cout << std::format("{:#015x}", 0x78) << '\n';

    std::cout << '\n';

    std::cout << std::format("{:g}", 120.0) << '\n';
    std::cout << std::format("{:#g}", 120.0) << '\n';

    std::cout << '\n';
   
}