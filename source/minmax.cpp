// minmax.cpp

#include <experimental/simd>
#include <iomanip>
#include <iostream>

namespace stdx = std::experimental;
 
void println(auto rem, auto const v) {
    std::cout << rem << ": ";
    for (std::size_t i = 0; i != v.size(); ++i)
        std::cout << std::setw(2) << v[i] << ' ';
    std::cout << '\n';
}

void printPairs(auto rem, auto const v1) {
    std::cout << rem << ": ";
    for (std::size_t i = 0; i != v1.first.size(); ++i)
        std::cout << '(' << v1.first[i] << ", " << v1.second[i] << ')' << ' ';
    std::cout << '\n';
}

int main() {

    stdx::fixed_size_simd<int, 8> a{[](int i) {
        static constexpr auto c = {10, 9, 8, 7, 6, 5, 4, 3};
        return c.begin()[i];
    }};
    println("a", a);
    
    stdx::fixed_size_simd<int, 8> b{[](int i) {
        static constexpr auto c = {3, 4, 5, 6, 7, 8, 9, 10,};
        return c.begin()[i];
    }};
    println("b", b);

    std::cout << '\n';

   auto minimum = stdx::min(a, b);
   println("minimum", minimum);

   auto maximum = stdx::max(a, b);
   println("maximum", maximum);

   /*
   auto minmax = stdx::minmax(a, b);
   printPairs("minmax", minmax);
   */

}