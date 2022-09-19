// mainSOIF1.cpp

#include <iostream>

extern int staticA;   
auto staticB = staticA;

int main() {
    
    std::cout << '\n';
    
    std::cout << "staticB: " << staticB << '\n';
    
    std::cout << '\n';
    
}