// formatFillAlign.cpp

#include <format>
#include <iostream>
 
int main() {

    std::cout << '\n';
    
    int num = 2020;

    std::cout << std::format("{:6}", num) << '\n'; 
    std::cout << std::format("{:6}", 'x') << '\n';   
    std::cout << std::format("{:*<6}", 'x') << '\n';
    std::cout << std::format("{:*>6}", 'x') << '\n';
    std::cout << std::format("{:*^6}", 'x') << '\n';
    std::cout << std::format("{:6d}", num) << '\n';
    std::cout << std::format("{:6}", true) << '\n';

    std::cout << '\n';
   
}