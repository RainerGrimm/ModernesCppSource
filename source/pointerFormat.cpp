// pointerFormat.cpp

#include <format>
#include <iostream>

int main() {
 
     std::cout << '\n';

    double d = 123.456789;

    std::cout << std::format("{}", static_cast<void*>(&d)) << '\n';
    std::cout << std::format("{}", static_cast<const void*>(&d)) << '\n';
    std::cout << std::format("{}", nullptr) << '\n';

    std::cout << '\n';

}