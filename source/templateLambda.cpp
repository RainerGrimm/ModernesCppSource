// templateLambda.cpp

#include <iostream>
#include <string>
#include <vector>

auto sumInt = [](int fir, int sec) { return fir + sec; };            // only to int convertible types (C++11)
auto sumGen = [](auto fir, auto sec) { return fir + sec; };          // arbitrary types (C++14)
auto sumDec = [](auto fir, decltype(fir) sec) { return fir + sec; }; // arbitrary, but convertible types (C++11)
auto sumTem = []<typename T>(T fir, T sec) { return fir + sec; };    // arbitrary, but identical types (C++20)

int main() {
    
    std::cout << std::endl;

    std::cout << "sumInt(2000, 11): " << sumInt(2000, 11) << std::endl;
    std::cout << "sumGen(2000, 11): " << sumGen(2000, 11) << std::endl;
    std::cout << "sumDec(2000, 11): " << sumDec(2000, 11) << std::endl;
    std::cout << "sumTem(2000, 11): " << sumTem(2000, 11) << std::endl;
    
    std::cout << std::endl;

    std::string hello = "Hello ";
    std::string world = "world"; 
    // std::cout << "sumInt(hello, world): " << sumInt(hello, world) << std::endl; ERROR
    std::cout << "sumGen(hello, world): " << sumGen(hello, world) << std::endl;
    std::cout << "sumDec(hello, world): " << sumDec(hello, world) << std::endl;
    std::cout << "sumTem(hello, world): " << sumTem(hello, world) << std::endl;
    
    
    std::cout << std::endl;
    
    std::cout << "sumInt(true, 2010): " << sumInt(true, 2010) << std::endl;
    std::cout << "sumGen(true, 2010): " << sumGen(true, 2010) << std::endl;
    std::cout << "sumDec(true, 2010): " << sumDec(true, 2010) << std::endl; 
    // std::cout << "sumTem(true, 2010): " << sumTem(true, 2010) << std::endl; ERROR
    
    std::cout << std::endl;
    
}

