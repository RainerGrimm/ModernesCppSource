// rangeBasedForLoopInitializer.cpp

#include <iostream>
#include <vector>

int main() {

    for (auto vec = std::vector{1, 2, 3}; auto v : vec) {
        std::cout << v << " ";
    }
    
    std::cout << "\n\n";
    
    for (auto initList = {1, 2, 3}; auto e : initList) {
        e *= e;
        std::cout << e << " ";
    }
    
    std::cout << "\n\n";
    
    using namespace std::string_literals;
    for (auto str = "Hello World"s; auto c: str) {
        std::cout << c << " ";
    }
     
}
