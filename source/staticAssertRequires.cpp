// staticAssertRequires.cpp

#include <concepts>
#include <iostream>

struct Fir {                   // (4)
    int count() const {
        return 2020;
    }
};

struct Sec {
    int size() const {
        return 2021;
    }
};

int main() {

    std::cout << '\n';
   
    Fir fir;
    static_assert(requires(Fir fir){ { fir.count() } -> std::convertible_to<int>; });     // (1)

    Sec sec;
    static_assert(requires(Sec sec){ { sec.count() } -> std::convertible_to<int>; });     // (2)

    int third;
    static_assert(requires(int third){ { third.count() } -> std::convertible_to<int>; }); // (3)

    std::cout << '\n';

}