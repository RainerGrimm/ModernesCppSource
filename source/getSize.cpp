// getSize.cpp

#include <experimental/meta>
#include <array>
#include <iostream>
#include <ranges>
#include <algorithm> 

constexpr std::array types = {^int, ^float, ^double};
constexpr std::array sizes = []{
  std::array<std::size_t, types.size()> r;
  std::ranges::transform(types, r.begin(), std::meta::size_of);
  return r;
}();

int main() {

    std::cout << '\n';
    
    std::cout << "Types and their sizes:\n";
    for (std::size_t i = 0; i < types.size(); ++i) {
        std::cout << "Size: " << sizes[i] << " bytes\n";
    }

    std::cout << '\n';
    
}