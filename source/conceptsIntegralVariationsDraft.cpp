// conceptsIntegralVariationsDraft.cpp

#include <type_traits>
#include <iostream>

template<typename T>                                  // (1)
concept Integral = std::is_integral<T>::value;       

template<typename T>                                  // (2)
requires Integral<T>
T gcd(T a, T b){
    if( b == 0 ) return a;
    else return gcd(b, a % b);
}

template<typename T>                                  // (3)
T gcd1(T a, T b) requires Integral<T>{
    if( b == 0 ){ return a; }
    else return gcd(b, a % b);
}

template<Integral T>                                  // (4)
T gcd2(T a, T b){
    if( b == 0 ){ return a; }
    else return gcd(b, a % b);
}

Integral auto gcd3(Integral auto a, Integral auto b){ // (5)
    if( b == 0 ){ return a; }
    else return gcd(b, a % b);
}

auto gcd4(auto a, auto b){                            // (6)
    if( b == 0 ){ return a; }
    return gcd(b, a % b);
}

int main(){

    std::cout << std::endl;

    std::cout << "gcd(100, 10)= "  <<  gcd(100, 10)  << std::endl;
    std::cout << "gcd1(100, 10)= " <<  gcd1(100, 10)  << std::endl;
    std::cout << "gcd2(100, 10)= " <<  gcd2(100, 10)  << std::endl;
    std::cout << "gcd3(100, 10)= " <<  gcd3(100, 10)  << std::endl;
    std::cout << "gcd4(100, 10)= " <<  gcd3(100, 10)  << std::endl;

    std::cout << std::endl;

}
