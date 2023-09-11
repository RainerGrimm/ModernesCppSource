// mdspanLayout.cpp

#include <mdspan>
#include <iostream>
#include <vector>

int main() {
    
    std::vector myVec{1, 2, 3, 4, 5, 6, 7, 8};

    std::mdspan<int, std::extents<std::size_t, std::dynamic_extent, std::dynamic_extent>, std::layout_right> m2{myVec.data(), 4, 2};
    std::cout << "m.rank(): " << m.rank() << '\n';

    for (std::size_t i = 0; i < m.extent(0); ++i) {
        for (std::size_t j = 0; j < m.extent(1); ++j) {
            std::cout << m[i, j] << ' ';  
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    std::mdspan<int, std::extents<std::size_t, std::dynamic_extent, std::dynamic_extent>, std::layout_left> m2{myVec.data(), 4, 2};
    std::cout << "m2.rank(): " << m2.rank() << '\n';

    for (std::size_t i = 0; i < m2.extent(0); ++i) {
        for (std::size_t j = 0; j < m2.extent(1); ++j) {
        std::cout << m2[i, j] << ' ';  
    }
    std::cout << '\n';
  }

}