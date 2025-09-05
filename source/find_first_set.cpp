// find_first_set.cpp

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

    stdx::simd_mask<short> x{0};
    println("x", x);

    x[1] = true;
    x[x.size() - 1] = true;
    println("x", x);

    auto first = stdx::find_first_set(x);
    std::cout << "find_first_set(x): " << first << '\n';

    auto last = stdx::find_last_set(x);
    std::cout << "find_last_set(x): " << last<< '\n';
    
}