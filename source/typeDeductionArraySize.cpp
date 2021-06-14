// typeDeductionArraySize.cpp

#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
std::size_t funcArraySize(T (&arr)[N]) { 
    return N;
}

int main() {

    std::cout << '\n';

    int intArray[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    funcArraySize(intArray);

    std::cout << "funcArraySize(intArray): " << funcArraySize(intArray) << '\n';

    std::cout << '\n';
    
}