// generator.cpp

#include <generator>
#include <ranges>
#include <iostream>
 
std::generator<int> fib() {
    co_yield 0;                    // (1)
    auto a = 0;
    auto b = 1;
    for(auto n : std::views::iota(0)) {  
        auto next = a + b;
        a = b;
        b = next;
        co_yield next;            // (2)   
    }
}

int main() {
    for (auto f : fib() | std::views::take(10)) {
        std::cout << f << " ";
    }
}