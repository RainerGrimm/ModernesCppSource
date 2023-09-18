// bindFrontBack.cpp

#include <functional>
#include <iostream>
#include <string>

int main() {

    std::cout << '\n';
    
    auto add = [](std::string a, std::string b, std::string c) { 
        return a + b + c;
    };

    auto two_three = std::bind_front(add, "one ");
    std::cout << two_three("two ", "three ") << '\n';

    auto one_two = std::bind_back(add, "three ");
    std::cout << one_two("one ", "two ") << '\n';  

    std::cout << '\n';
    
}