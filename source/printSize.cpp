// printSize.cpp

#include <iostream>

using namespace std::literals;

template <typename ... Args>
void printSize(Args&& ... args){
    std::cout << sizeof...(Args) << ' ';              // (1)
    std::cout << sizeof...(args) << '\n';             // (2)
}

int main() {

    std::cout << '\n';

    printSize();                                       // (3)
    printSize("C string", "C++ string"s, 2011, true);  // (4)

    std::cout << '\n';

}