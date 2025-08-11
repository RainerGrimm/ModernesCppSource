// clamp.cpp

#include <cstddef>
#include <cstdint>
#include <experimental/simd>
#include <iomanip>
#include <iostream>

namespace stdx = std::experimental;
 
void println(auto rem, auto const v) {
    std::cout << rem << ": ";
    for (std::size_t i = 0; i != v.size(); ++i)
        std::cout << std::setw(4) << v[i] << ' ';
    std::cout << '\n';
}
 
int main() {

    std::cout << "INT8_MIN: " << INT8_MIN << '\n';
    std::cout << "INT8_MAX: " << INT8_MAX << '\n';
    std::cout << "UINT8_MAX: " << UINT8_MAX << '\n';

    std::cout << '\n';

    stdx::fixed_size_simd<int, 8> a{[](int i) {
        static constexpr auto c = {-129, -128, -1, 0, 42, 127, 128, 255};
        return c.begin()[i];
    }};
    println("a", a);
 
    stdx::fixed_size_simd<int, 8> lo1{INT8_MIN};
    stdx::fixed_size_simd<int, 8> hi1{INT8_MAX};
    const auto b = stdx::clamp(a, lo1, hi1);
    println("b", b);
 
    stdx::fixed_size_simd<int, 8> lo2{0};
    stdx::fixed_size_simd<int, 8> hi2{UINT8_MAX};
    const auto c = stdx::clamp(a, lo2, hi2);
    println("c", c);

}