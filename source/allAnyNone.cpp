// allAnyNone.cpp

#include <iostream>
#include <type_traits>

template<typename T>
concept Arithmetic = std::is_arithmetic<T>::value;

template<Arithmetic... Args>
bool all(Args... args) { return (... && args); }

template<Arithmetic... Args>
bool any(Args... args) { return (... || args); }

template<Arithmetic... Args>
bool none(Args... args) { return !(... || args); }

int main(){

    std::cout << std::boolalpha << std::endl;
               
    std::cout << "all(5, true, 5.5, false): " << all(5, true, 5.5, false) << std::endl;  

    std::cout << "any(5, true, 5.5, false): " << any(5, true, 5.5, false) << std::endl; 
              
    std::cout << "none(5, true, 5.5, false): " << none(5, true, 5.5, false) << std::endl;     
    
}