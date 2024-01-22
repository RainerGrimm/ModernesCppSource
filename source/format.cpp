// format.cpp

#include <format>
#include <iostream>
#include <iterator>
#include <string>
 
int main() {
    
    std::cout << '\n';

    std::cout << std::format("Hello, C++{}!\n", "20") << '\n';  // (1)

    std::string buffer;
 
    std::format_to(                                             // (2)
        std::back_inserter(buffer), 
        "Hello, C++{}!\n",          
        "20");    
        
    std::cout << buffer << '\n';

    buffer.clear(); 

    std::format_to_n(                                           // (3)
        std::back_inserter(buffer), 5, 
        "Hello, C++{}!\n",          
        "20");    
        
    std::cout << buffer << '\n';

    
    std::cout << '\n';
   
}