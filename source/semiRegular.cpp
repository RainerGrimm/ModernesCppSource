// semiRegular.cpp

#include <iostream>
#include <type_traits>

int main(){
    
    std::cout << std::boolalpha << std::endl;
    
    std::cout << "std::is_default_constructible<int&>::value: " << std::is_default_constructible<int&>::value << std::endl;
    std::cout << "std::is_copy_constructible<int&>::value: " << std::is_copy_constructible<int&>::value << std::endl;
    std::cout << "std::is_copy_assignable<int&>::value: " << std::is_copy_assignable<int&>::value << std::endl;
    std::cout << "std::is_move_constructible<int&>::value: " << std::is_move_constructible<int&>::value << std::endl;
    std::cout << "std::is_move_assignable<int&>::value: " << std::is_move_assignable<int&>::value << std::endl;
    std::cout << "std::is_destructible<int&>::value: " << std::is_destructible<int&>::value << std::endl;
    std::cout << std::endl;
    std::cout << "std::is_swappable<int&>::value: " << std::is_swappable<int&>::value << std::endl;  // requires C++17

    std::cout << std::endl;

}
