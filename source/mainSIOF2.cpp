// mainSOIF2.cpp

#include <iostream>

int& staticA();

auto staticB = staticA();

int main() {
    
    std::cout << std::endl;
    
    std::cout << "staticB: " << staticB << std::endl;
    
    std::cout << std::endl;
    
}
