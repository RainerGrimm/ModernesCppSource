// rangesIotaV3.cpp

#include <iostream>
#include <numeric>
#include <range/v3/all.hpp>
#include <vector>

int main() {
    
    std::cout << std::boolalpha;
    
    std::vector<int> vec;
    std::vector<int> vec2;
    
    for (int i: ranges::views::iota(0, 10)) vec.push_back(i);                
         
    for (int i: ranges::views::iota(0) | ranges::views::take(10)) vec2.push_back(i);
    
    std::cout << "vec == vec2: " << (vec == vec2) << std::endl;
    
    for (int i: vec) std::cout << i << " ";
                           
}
