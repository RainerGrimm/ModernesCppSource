// multVariadicTemplates.cpp

#include <iostream>

template<int ...>
struct Mult;

template<>
struct Mult<> {
    static const int value = 1;
};

template<int i, int ... tail>
struct Mult<i, tail ...> {
    static const int value = i * Mult<tail ...>::value;
};

int main(){

    std::cout << '\n';

    std::cout << "Mult<10>::value: " << Mult<10>::value << '\n';
    std::cout << "Mult<10,10,10>::value: " << Mult<10, 10, 10>::value << '\n';
    std::cout << "Mult<1,2,3,4,5>::value: " << Mult<1, 2, 3, 4, 5>::value << '\n';

    std::cout << '\n';

}