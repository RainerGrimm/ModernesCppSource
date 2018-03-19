// overflow.cpp

#include <cstddef>
#include <iostream>

int main(){
    
    std::cout << std::endl;
    
    int max{100000};    
    short x{0};                     // (2)
    std::size_t count{0};
    while (x < max && count < 20){
        std::cout << x << " ";
        x += 10000;                  // (1)
        ++count;
    }
    
    std::cout << "\n\n";
}
