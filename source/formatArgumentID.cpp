// formatArgumentID.cpp

#include <format>
#include <iostream>
#include <string>
 
int main() {
    
    std::cout << '\n';

    std::cout << std::format("{} {}: {}!\n", "Hello", "World", 2020);        

    std::cout << std::format("{1} {0}: {2}!\n", "World", "Hello", 2020);     

    std::cout << std::format("{0} {0} {1}: {2}!\n", "Hello", "World", 2020); 

    std::cout << std::format("{0}: {2}!\n", "Hello", "World", 2020);         
    
    std::cout << '\n';
   
}