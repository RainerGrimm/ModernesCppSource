// factorialConstexprIf.cpp

#include <iostream>

template <int N>                                                                // (1)
struct Factorial{
    static int const value = N * Factorial<N-1>::value;
};

template <>                                                                     // (2)
struct Factorial<1>{
    static int const value = 1;
};

template <int N>                                                                // (3)
constexpr int factorial() {
    if constexpr (N >= 2) 
        return N * factorial<N-1>();
    else 
        return N;
}

int main(){
    
    static_assert(Factorial<5>::value == factorial<5>());
    static_assert(Factorial<10>::value == factorial<10>());

}