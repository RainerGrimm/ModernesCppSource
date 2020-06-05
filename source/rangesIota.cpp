// rangesIota.cpp

#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

int main() {
    
    std::cout << std::boolalpha;
    
    std::vector<int> vec;
    std::vector<int> vec2;
    
    for (int i: std::views::iota(0, 10)) vec.push_back(i);                         
         
    for (int i: std::views::iota(0) | std::views::take(10)) vec2.push_back(i);  
    
    std::cout << "vec == vec2: " << (vec == vec2) << '\n';
    
    for (int i: vec) std::cout << i << " ";            
                        
}
