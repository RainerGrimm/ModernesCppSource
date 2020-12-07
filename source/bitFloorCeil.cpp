// bitFloorCeil.cpp

#include <bit>
#include <bitset>
#include <iostream>
 
int main() {

    std::cout << std::endl;
    
    std::cout << std::boolalpha;
    
    for (auto i = 2u; i < 8u; ++i) {
         std::cout << "bit_floor(" << std::bitset<8>(i) << ") = " 
                   << std::bit_floor(i) << '\n';

        std::cout << "bit_ceil(" << std::bitset<8>(i) << ") = " 
                  << std::bit_ceil(i) << '\n';

        std::cout << "bit_width(" << std::bitset<8>(i) << ") = " 
                  << std::bit_width(i) << '\n';
                  
        std::cout << "bit_popcount(" << std::bitset<8>(i) << ") = " 
                  << std::popcount(i) << '\n';   
        
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    
}