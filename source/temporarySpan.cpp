// temporarySpan.cpp

#include <iostream>
#include <span>
#include <vector>

std::vector<int> getVector() {                          
    return {1, 2, 3, 4, 5};
}

int main() {

     std::cout << '\n';
    
    std::vector<int> myVec{1, 2, 3, 4, 5};              
    std::span<int, 5> mySpan1{myVec};                  
    std::span<int, 5> mySpan2{getVector().begin(), 5};  

    for (auto v: std::span{myVec}) std::cout << v << " ";
    std::cout << '\n';
    for (auto v: std::span{getVector().begin(), 5}) std::cout << v << " ";  

     std::cout << "\n\n";
    
}