// conceptsArithmeticTS.cpp

#include <type_traits>
#include <iostream>

template<typename T>
concept bool Arithmetic(){
    return std::is_arithmetic<T>::value;
}

Arithmetic sub(Arithmetic fir, Arithmetic sec){
    return fir - sec;
}

int main(){

    std::cout << std::endl;

    std::cout << "sub(6, 5): " << sub(6, 5) << std::endl;      // (1)
    std::cout << "sub(5.5, 5): " << sub(5.5, 5) << std::endl;  // (2)

    std::cout << std::endl;

}
