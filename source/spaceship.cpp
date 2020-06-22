// spaceship.cpp

#include <compare>
#include <iostream>
#include <string>
#include <vector>

int main() {
    
    std::cout << std::endl;
    
    int a(2011);
    int b(2014);
    auto res = a <=> b;                 // (1)
    if (res < 0) std::cout << "a < b" << std::endl;
    else if (res == 0) std::cout << "a == b" << std::endl;
    else if (res > 0) std::cout << "a > b" << std::endl;

    std::string str1("2014");
    std::string str2("2011");
    auto res2 = str1 <=> str2;          // (2)
    if (res2 < 0) std::cout << "str1 < str2" << std::endl;
    else if (res2 == 0) std::cout << "str1 == str2" << std::endl;
    else if (res2 > 0) std::cout << "str1 > str2" << std::endl;
    
    std::vector<int> vec1{1, 2, 3};
    std::vector<int> vec2{1, 2, 3};
    auto res3 = vec1 <=> vec2;          // (3)
    if (res3 < 0) std::cout << "vec1 < vec2" << std::endl;
    else if (res3 == 0) std::cout << "vec1 == vec2" << std::endl;
    else if (res3 > 0) std::cout << "vec1 > vec2" << std::endl;
    
    std::cout << std::endl;
    
}