// range2.cpp

#include "xrange2.hpp"

#include <iostream>
#include <range/v3/all.hpp>
#include <vector>

        
int main() {
    
    std::cout << std::endl;

    auto res = xrange(1, 10);
    for (auto i: res) std::cout << i << " ";
    
    std::cout << "\n\n";
    
    res = xrange(1, 50, 5);
    for (auto i: res) std::cout << i << " ";
    
    std::cout << "\n\n";
    
    auto res2 = xrange(20, 10, -1);
    for (auto i: res2) std::cout << i << " ";
    
    std::cout << "\n\n";
    
    res2 = xrange(50, 10, -5);
    for (auto i: res2) std::cout << i << " ";
    
    std::cout << "\n\n";
    
    res = xrange(1, 1'000'000'000'000'000'000);
    // for (auto i: res) std::cout << i << " ";
    
    for (auto i: res | ranges::views::take(10)) std::cout << i << " ";
    
    std::cout << "\n\n";
    
    for (auto i: res | ranges::views::drop_while([](int i){ return i < 1'000'000; })
                     | ranges::views::take_while([](int i){ return i < 1'000'010; })){
        std::cout << i << " ";
    }
    
    std::cout << "\n\n";
    
}
