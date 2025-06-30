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
    where(x < 0, x) = -x;
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
 
    const auto e = d * d;
    println("e", e);
 
    const auto inner_product = stdx::reduce(e);
    std::cout << "inner product: " << inner_product << '\n';
 
    const stdx::fixed_size_simd<long double, 16> x([](int i) { return i; });
    println("x", x);
    println("cos²(x) + sin²(x)", stdx::pow(stdx::cos(x), 2) + stdx::pow(stdx::sin(x), 2));
}