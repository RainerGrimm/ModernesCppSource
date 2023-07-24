// factorial_cpp11.cpp

#include <iostream>

constexpr int factorial(unsigned int n){
    return n > 0 ? n * factorial(n - 1): 1;
}

int main(){
    
    std::cout << '\n';
    
    std::cout << "factorial(10)         " << factorial(10) << '\n';
    
    std::cout << '\n';

}