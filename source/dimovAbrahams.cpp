// dimovAbrahams.cpp

#include <iostream>
#include <string>

// getTypeName

template <typename T> // (1) primary template
std::string getTypeName(T)
{
    return "unknown";
}

template <typename T> // (2) primary template that overloads (1)
std::string getTypeName(T*)
{
    return "pointer";
}

template <> // (3) explicit specialization of (2)
std::string getTypeName(int*)
{
    return "int pointer";
}

// getTypeName2

template <typename T> // (4) primary template
std::string getTypeName2(T)
{
    return "unknown";
}

template <> // (5) explicit specialization of (4)
std::string getTypeName2(int*)
{
    return "int pointer";
}

template <typename T> // (6) primary template that overloads (4)
std::string getTypeName2(T*)
{
    return "pointer";
}

int main()
{

    std::cout << std::endl;

    int* p;

    std::cout << "getTypeName(p): " << getTypeName(p) << std::endl;
    std::cout << "getTypeName2(p): " << getTypeName2(p) << std::endl;

    std::cout << std::endl;
}
