// formatWidthPrecision.cpp

#include <format>
#include <iostream>
#include <string>

int main() {

    int i = 123456789;
    double d = 123.456789;

    std::cout << "---" << std::format("{}", i) << "---\n";
    std::cout << "---" << std::format("{:15}", i) << "---\n"; // (w = 15)
    std::cout << "---" << std::format("{:}", i) << "---\n";   // (w = 15)             

    std::cout << '\n';

    std::cout << "---" << std::format("{}", d) << "---\n";    
    std::cout << "---" << std::format("{:15}", d) << "---\n"; // (w = 15)
    std::cout << "---" << std::format("{:}", d) << "---\n";   // (w = 15)

    std::cout << '\n';

    std::string s= "Only a test";

    std::cout << "---" << std::format("{:10.50}", d) << "---\n"; // (w = 10, p = 50)   
    std::cout << "---" << std::format("{:{}.{}}", d, 10, 50) << "---\n";  // (w = 10,  
                                                                         //  p = 50)
    std::cout << "---" << std::format("{:10.5}", d) << "---\n";  // (w = 10, p = 5)
    std::cout << "---" << std::format("{:{}.{}}", d, 10, 5) << "---\n";  // (w = 10,
                                                                         //  p = 5)

    std::cout << '\n';

    std::cout << "---" << std::format("{:.500}", s) << "---\n";      // (p = 500)      
    std::cout << "---" << std::format("{:.{}}", s, 500) << "---\n";  // (p = 500)      
    std::cout << "---" << std::format("{:.5}", s) << "---\n";        // (p = 5)

}