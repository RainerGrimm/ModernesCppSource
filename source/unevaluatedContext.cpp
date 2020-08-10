// unevaluatedContext.cpp

#include <iostream>
#include <typeinfo>  // typeid

int add1(int, int);                       // declaration
int add2(int a, int b) { return a + b; }  // definition

int main() {

    std::cout << std::endl;

    std::cout << "typeid(add1).name(): " 
              << typeid(add1).name() << std::endl;                 // (1)
    
    decltype(*add1) add = add2;                                    // (2)
    
    std::cout << "add(2000, 20): " << add(2000, 20) << std::endl;
    
    std::cout << std::endl;
    
}
