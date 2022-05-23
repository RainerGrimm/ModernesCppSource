// lazyRanges.cpp

#include <iostream>
#include <ranges>

int main() {
                                    
    
    std::cout << "\n";

    for (int i: std::views::iota(1'000'000, 1'000'010)) {     // (1)
        std::cout << i << " ";  
    }

    std::cout << "\n\n";
                                         
    for (int i: std::views::iota(1'000'000)                   // (2)
                | std::views::take(10)) {
        std::cout << i << " ";  
    }

    std::cout << "\n\n";

    for (int i: std::views::iota(1'000'000)                  // (3)
                | std::views::take_while([](auto i) { return i < 1'000'010; } )) {
        std::cout << i << " ";  
    }

    std::cout << "\n\n";

}