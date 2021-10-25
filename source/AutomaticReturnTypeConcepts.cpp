// automaticReturnTypeTypeConcepts.cpp

#include <iostream>
#include <typeinfo>
#include <type_traits>

template<typename T>
concept Arithmetic = std::is_arithmetic<T>::value;

Arithmetic auto sum(Arithmetic auto t, Arithmetic auto t2) {
    return t + t2;
}


int main() {

    std::cout << '\n';

    std::cout << typeid(sum(5.5, 5.5)).name() << '\n';     // double
    std::cout << typeid(sum(5.5, true)).name() << '\n';    // double
    std::cout << typeid(sum(true, 5.5)).name() << '\n';    // double
    std::cout << typeid(sum(true, false)).name() << '\n';  // int

    std::cout << '\n';

}