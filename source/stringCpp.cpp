// stringCpp.cpp

#include <iostream>
#include <string>

int main()
{

    std::string text { "The Text is not too long." };

    std::cout << "text.size(): " << text.size() << std::endl;
    std::cout << text << std::endl;

    text += " And can still grow!";

    std::cout << "text.size(): " << text.size() << std::endl;
    std::cout << text << std::endl;
}
