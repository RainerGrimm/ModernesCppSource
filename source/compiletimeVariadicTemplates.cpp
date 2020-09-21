// compiletimeVariadicTemplates.cpp

#include <iostream>

template<int...>
struct sum;

template<>
struct sum<> {
  static constexpr int value = 0;
};

template<int i, int... tail>
struct sum<i, tail...> {
  static constexpr int value = i + sum<tail...>::value;
};

template<int...>
struct product;

template<>
struct product<> {
  static constexpr int value = 1;
};

template<int i, int... tail>
struct product<i, tail...> {
  static constexpr int value = i * product<tail...>::value;
};


int main() {

    std::cout << std::endl;

    std::cout << "sum<1, 2, 3, 4, 5>::value: " << sum<1, 2, 3, 4, 5>::value << std::endl;
    std::cout << "product<1, 2, 3, 4, 5>::value: " << product<1, 2, 3, 4, 5>::value << std::endl;

    std::cout << std::endl;

}
