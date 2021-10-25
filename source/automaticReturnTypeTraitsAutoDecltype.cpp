// automaticReturnTypeTypeAutoDecltype.cpp

#include <iostream>
#include <typeinfo>
#include <type_traits>

template <typename T, typename T2>
auto sum(T t, T2 t2) -> decltype(t + t2) {
    return t + t2;
}


int main() {

    std::cout << '\n';

    std::cout << typeid(sum(5.5, 5.5)).name() << '\n';     // double
    std::cout << typeid(sum(5.5, true)).name() << '\n';    // double
    std::cout << typeid(sum(true, 5.5)).name() << '\n';    // double
    std::cout << typeid(sum(true, false)).name() << '\n';  // bool

    std::cout << '\n';

}