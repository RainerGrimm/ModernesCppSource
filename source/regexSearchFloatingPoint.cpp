// regexSearchFloatingPoint.cpp

#include <regex>
#include <iostream>
#include <string>

int main(){

    std::cout << std::endl;

    std::string text = "A text with floating pointer number \t5.5\t\\DELIMITER and more text.";
    std::cout << text << std::endl;
    
    std::cout << std::endl;

    std::regex rgx("\\t[0-9]+\\.[0-9]+\\t\\\\DELIMITER");
    std::regex rgxRaw(R"(\t[0-9]+\.[0-9]+\t\\DELIMITER)");

    if (std::regex_search(text, rgx)) std::cout << "found with rgx" << std::endl;
    if (std::regex_search(text, rgxRaw)) std::cout << "found with rgxRaw" << std::endl;

    std::cout << std::endl;

}
