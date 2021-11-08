// removeConst.cpp

#include <iostream>
#include <type_traits>

template<typename T >
    struct removeConst {
    using type = T; // (1)
};

template<typename T >
    struct removeConst<const T> {
    using type = T; // (2)
};

int main() {

    std::cout << std::boolalpha;
    std::cout << std::is_same<int, removeConst<int>::type>::value << '\n';       // true
    std::cout << std::is_same<int, removeConst<const int>::type>::value << '\n'; // true

}