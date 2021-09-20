// overloadPattern.cpp

#include <iostream>

template<typename... Ts> struct Overload : Ts... { using Ts::operator()...; };


int main() {

    std::cout << '\n';

    auto TypeOfIntegral = Overload{
        [](int) { return "  int"; },
        [](unsigned int) { return " unsigned int"; },
        [](long int) { return " long int"; },
        [](long long int) { return "long long int"; },
        [](auto) { return "unknown type"; },
    };

    std::cout << "TypeOfIntegral(5): " << TypeOfIntegral(5) << '\n';
    std::cout << "TypeOfIntegral(5u): " << TypeOfIntegral(5u) << '\n';
    std::cout << "TypeOfIntegral(5U): " << TypeOfIntegral(5U) << '\n';
    std::cout << "TypeOfIntegral(5l): " << TypeOfIntegral(5l) << '\n';
    std::cout << "TypeOfIntegral(5L): " << TypeOfIntegral(5L) << '\n';
    std::cout << "TypeOfIntegral(5ll): " << TypeOfIntegral(5ll) << '\n';
    std::cout << "TypeOfIntegral(5LL): " << TypeOfIntegral(5LL) << '\n';

    std::cout << '\n';

    std::cout << "TypeOfIntegral(5ul): " << TypeOfIntegral(5ul) << '\n';
    std::cout << "TypeOfIntegral(5.5): " << TypeOfIntegral(5.5) << '\n';

    std::cout << '\n'; 

}