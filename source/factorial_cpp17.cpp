// factorial_cpp17.cpp

#include <iostream>

template <unsigned int N>                                             
constexpr int factorial() {
    if constexpr (N > 0) 
        return N * factorial<N - 1>();
    else 
        return 1;
}

int main(){
    
    std::cout << '\n';
    
    std::cout << "factorial<10>() " << factorial<10>() << '\n';
    
    std::cout << '\n';

}