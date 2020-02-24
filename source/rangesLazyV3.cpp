// rangesLazyV3.cpp

#include <iostream>
#include <range/v3/all.hpp>


bool isPrime(int i) {
    for (int j=2; j*j <= i; ++j){
        if (i % j == 0) return false;
    }
    return true;
}

int main() {
    
    std::cout << "Numbers from 1000000 to 1001000 (dispayed each 100th): " << std::endl;
    for (int i: ranges::views::iota(1000000, 1001000)) {
        if (i % 100 == 0) std::cout << i << " ";  
    }
    
    std::cout << "\n\n";
    
    auto odd = [](int i){ return i % 2 == 1; };
    std::cout << "Odd numbers from 1000000 to 1001000 (displayed each 100th): " << std::endl;
    for (int i: ranges::views::iota(1000000, 1001000) | ranges::views::filter(odd)) {
         if (i % 100 == 1) std::cout << i << " ";  
    }
    
    std::cout << "\n\n";
    
    std::cout << "Prime numbers from 1000000 to 1001000: " << std::endl;
    for (int i: ranges::views::iota(1000000, 1001000) | ranges::views::filter(odd) 
                                                      | ranges::views::filter(isPrime)) {
        std::cout << i << " ";  
    }
    
    std::cout << "\n\n";
    
    std::cout << "20 prime numbers starting with 1000000: " << std::endl;
    for (int i: ranges::views::iota(1000000) | ranges::views::filter(odd) 
                                             | ranges::views::filter(isPrime) 
                                             | ranges::views::take(20)) {
        std::cout << i << " ";  
    }

}
