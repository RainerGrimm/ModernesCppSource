// primesLazy.cpp

#include <iostream>
#include <ranges>


bool isPrime(int i) {
    for (int j=2; j*j <= i; ++j){
        if (i % j == 0) return false;
    }
    return true;
}

int main() {
                                        
    std::cout << '\n';
                                         
    auto odd = [](int i){ return i % 2 == 1; };

    for (int i: std::views::iota(1'000'000) | std::views::filter(odd) 
                                            | std::views::filter(isPrime) 
                                            | std::views::take(10)) {
        std::cout << i << " ";  
    }

    std::cout << '\n';

}