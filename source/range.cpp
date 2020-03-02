// range.cpp

#include <iostream>
#include <range/v3/all.hpp>
#include <vector>

std::vector<int> range(int begin, int end, int stepsize = 1) {
    std::vector<int> result{};
    if (begin < end) {
        auto boundary = [end](int i){ return i < end; };
        for (int i: ranges::views::iota(begin) | ranges::views::stride(stepsize) 
                                               | ranges::views::take_while(boundary)) {
            result.push_back(i);
        }
    }
    else {
        begin++;
        end++;
        stepsize *= -1;
        auto boundary = [begin](int i){ return i < begin; };
        for (int i: ranges::views::iota(end) | ranges::views::take_while(boundary) 
                                             | ranges::views::reverse 
                                             | ranges::views::stride(stepsize)) {
            result.push_back(i);
        }
    }
    return result;
}
        
int main() {
    
    std::cout << std::endl;

    // range(1, 50)    
    auto res = range(1, 50);
    for (auto i: res) std::cout << i << " ";
    
    std::cout << "\n\n";
    
    // range(1, 50, 5)
    res = range(1, 50, 5);
    for (auto i: res) std::cout << i << " ";
    
    std::cout << "\n\n";
    
    // range(50, 10, -1)
    res = range(50, 10, -1);
    for (auto i: res) std::cout << i << " ";
    
    std::cout << "\n\n";
    
    // range(50, 10, -5)
    res = range(50, 10, -5);
    for (auto i: res) std::cout << i << " ";
    
    std::cout << "\n\n";
    
}
