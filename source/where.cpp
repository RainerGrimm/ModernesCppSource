// where.cpp

#include <experimental/simd>
#include <iostream>
#include <string_view>
namespace stdx = std::experimental;
 
void println(std::string_view name, auto const& a)
{
    std::cout << name << ": ";
    for (std::size_t i{}; i != std::size(a); ++i)
        std::cout << a[i] << ' ';
    std::cout << '\n';
}
 
template<class A>
stdx::simd<int, A> my_abs(stdx::simd<int, A> x)
{
    where(x < 0, x) = -x; // Set elements where x is negative to their absolute value       
    return x;
}
 
int main()
{
    const stdx::native_simd<int> a = 1;
    println("a", a);
 
    const stdx::native_simd<int> b([](int i) { return i - 2; });
    println("b", b);
 
    const auto c = a + b;
    println("c", c);
 
    const auto d = my_abs(c);
    println("d", d);
 
}