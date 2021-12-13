// gcdIntegral.cpp

#include <iostream>
#include <type_traits>

template <typename T>
concept Integral = std::is_integral<T>::value;

template <typename T>
concept SignedIntegral = Integral<T> && std::is_signed<T>::value;

template <typename T>
concept UnsignedIntegral = Integral<T> && !SignedIntegral<T>;

Integral auto gcd(Integral auto a, decltype(a) b) {
    if( b == 0 ){ return a; }
    else{
        return gcd(b, a % b);
    }
}

int main() {

    std::cout << gcd(100, 33) << '\n';
    std::cout << gcd(3.5,4.0) << '\n';
    std::cout << gcd("100","10") << '\n';

}
