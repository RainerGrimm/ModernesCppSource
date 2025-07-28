// reduction.cpp

#include <array>
#include <experimental/simd>
#include <functional>
#include <iostream>
#include <string_view>

namespace stdx = std::experimental;
 
void println(std::string_view name, auto const& a) {
    std::cout << name << ": ";
    for (std::size_t i{}; i != std::size(a); ++i)
        std::cout << a[i] << ' ';
    std::cout << '\n';
}

 
int main() {

    const stdx::fixed_size_simd<int, 16> a([](int i) { return i; });    
    println("a", a);

    auto sum = stdx::reduce(a);
    std::cout << "sum: " << sum << "\n\n";

    const stdx::fixed_size_simd<int, 8> b([](int i) { return i + 1; });    
    println("b", b);

    auto product = stdx::reduce(b, std::multiplies<>());
    std::cout << "product: " << product <<  "\n\n";

    auto maximum = stdx::hmax(b);
    std::cout << "maximum: " << maximum <<  "\n\n";

    auto minimum = stdx::hmin(b);
    std::cout << "minimum: " << minimum <<  "\n\n";
    
}