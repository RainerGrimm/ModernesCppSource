// stringBoundsCheck.cpp

#include <stdexcept>
#include <iostream>
#include <string>
 
int main(){

    std::cout << std::endl;

    std::string str("1123456789"); 
 
    str.at(0) = '0';                                   // (1)
    
    std::cout << str << std::endl;
 
    std::cout << "str.size(): " << str.size() << '\n';
    std::cout << "str.capacity() = " << str.capacity() << '\n';
 
    try {
        str.at(12) = 'X';                              // (2)
    }
    catch (const std::out_of_range& exc) {
        std::cout << exc.what() << std::endl;
    }
    
    std::cout << std::endl;

}
    