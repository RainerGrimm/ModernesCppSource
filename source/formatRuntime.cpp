// formatRuntime.cpp

#include <format>
#include <iostream>
#include <iterator>
#include <string>
 
int main() {
    
    std::cout << '\n';

    std::string formatString = "Hello, C++{}!\n";

    std::cout << std::vformat(formatString, std::make_format_args("20")) << '\n';  

    std::string buffer;
 
    std::vformat_to(                                                               
        std::back_inserter(buffer), 
        formatString,          
        std::make_format_args("20"));    
        
    std::cout << buffer << '\n';
   
}