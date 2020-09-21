// constexprArray.cpp

#include <iostream>
#include <numeric>
#include <array>


int main() {

    std::cout << std::endl;

    constexpr std::array myArray{1, 2, 3, 4, 5};
    constexpr auto sum = std::accumulate(myArray.begin(), myArray.end(), 0);
    std::cout << "sum: "  << sum << std::endl;

    constexpr auto product = std::accumulate(myArray.begin(), myArray.end(), 1, std::multiplies<int>());
    std::cout << "product: "  << product << std::endl;

    constexpr auto product2 = std::accumulate(myArray.begin(), myArray.end(), 1, [](auto a, auto b) { return a * b;});
    std::cout << "product2: "  << product2 << std::endl;

    std::cout << std::endl;

}