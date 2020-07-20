// mainSOIF1.cpp

#include <iostream>

extern int staticA;
auto staticB = staticA;

int main() {
    
    std::cout << std::endl;
    
    std::cout << "staticB: " << staticB << std::endl;
    
    std::cout << std::endl;
    
}