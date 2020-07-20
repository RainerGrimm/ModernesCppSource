// mainSOIF3.cpp

#include <iostream>

extern constinit int staticA;

auto staticB = staticA;

int main() {
    
    std::cout << std::endl;
    
    std::cout << "staticB: " << staticB << std::endl;
    
    std::cout << std::endl;
    
}
