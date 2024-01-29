// formatSign.cpp

#include <format>
#include <iostream>
 
int main() {

    std::cout << '\n';

    std::cout << std::format("{0:},{0:+},{0:-},{0: }", 0) << '\n';
    std::cout << std::format("{0:},{0:+},{0:-},{0: }", -0) << '\n';
    std::cout << std::format("{0:},{0:+},{0:-},{0: }", 1) << '\n';
    std::cout << std::format("{0:},{0:+},{0:-},{0: }", -1) << '\n';

    std::cout << '\n';
   
}