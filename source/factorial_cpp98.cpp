// factorial_cpp98.cpp

#include <iostream>

template <unsigned int N>                                                                 
struct Factorial{
    static int const value = N * Factorial<N-1>::value;
};



template <>                                                                     
struct Factorial<0>{
    static int const value = 1;
};

int factorial(unsigned int n){
    return n > 0 ? n * factorial(n - 1): 1;
}

int main(){
    
    std::cout << '\n';
    
    std::cout << "Factorial<10>::value: " << Factorial<10>::value << '\n'; 
    std::cout << "factorial(10)         " << factorial(10) << '\n';
    
    std::cout << '\n';

}