// popcount.cpp

#include <experimental/simd>
#include <iostream>
#include <string_view>

namespace stdx = std::experimental;
 
void println(std::string_view name, auto const& a) {
    std::cout << std::boolalpha << name << ": ";
    for (std::size_t i{}; i != std::size(a); ++i)
        std::cout << a[i] << ' ';
    std::cout << '\n';
}

 
int main() {

    const stdx::native_simd<int> a = 1;
    println("a", a);
 
    const stdx::native_simd<int> b([](int i) { return i - 2; });
    println("b", b);
 
    const auto c = a + b;
    println("c", c);
 
    const stdx::native_simd_mask x = c < 0; 
    println("x", x);

    auto cnt = popcount(x);
    std::cout << "cnt: " << cnt << '\n';

}