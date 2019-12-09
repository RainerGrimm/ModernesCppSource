// placeholdersDraft.cpp

#include <iostream>
#include <type_traits>
#include <vector>

template<typename T>                                   // (1)
concept Integral = std::is_integral<T>::value;

Integral auto getIntegral(int val){                    // (2)
    return val;
}

int main(){

    std::cout << std::boolalpha << std::endl;
 
    std::vector<int> vec{1, 2, 3, 4, 5};
    for (Integral auto i: vec) std::cout << i << " ";  // (3)
 
    Integral auto b = true;                            // (4)
    std::cout << b << std::endl;

    Integral auto integ = getIntegral(10);             // (5)
    std::cout << integ << std::endl;

    auto integ1 = getIntegral(10);                     // (6)
    std::cout << integ1 << std::endl;

    std::cout << std::endl;

}
