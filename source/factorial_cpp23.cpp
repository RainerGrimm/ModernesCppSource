// factorial_cpp23.cpp

#include <iostream>

auto factorial = [](this auto&& self, unsigned int n) -> int { 
                    return (n > 1) ? self(n - 1)+self(n - 2) : 1;  
                 };

int main(){
    
    std::cout << '\n';
    
    std::cout << "factorial(10)         " << factorial(10) << '\n';
    
    std::cout << '\n';

}