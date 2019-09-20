// functionTemplateSpecialisation.cpp

#include <iostream>
#include <string>

template <typename T> // (1)
std::string getTypeName(T)
{
    return "unknown type";
}

template <> // (2)
std::string getTypeName<int>(int)
{
    return "int";
}

std::string getTypeName(double)
{ // (3)
    return "double";
}

int main()
{

    std::cout << std::endl;

    std::cout << "getTypeName(true): " << getTypeName(true) << std::endl;
    std::cout << "getTypeName(4711): " << getTypeName(4711) << std::endl;
    std::cout << "getTypeName(3.14): " << getTypeName(3.14) << std::endl;

    std::cout << std::endl;
}
