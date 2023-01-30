// referenceIsObject.cpp

#include <functional>
#include <iostream>
#include <type_traits>
 
int main() {

    std::cout << '\n';

    std::cout << std::boolalpha;
    std::cout << "std::is_object<int&>::value: " << std::is_object<int&>::value << '\n';
    std::cout << "std::is_object<std::reference_wrapper<int>>::value: " 
              << std::is_object<std::reference_wrapper<int>>::value << '\n';

    std::cout << '\n';
    
}