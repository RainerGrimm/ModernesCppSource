// vectorSum.cpp

#include <iostream>
#include <numeric>
#include <vector>

auto sum(std::vector<int> myVec){
    return std::accumulate(myVec.begin(), myVec.end(), 0);
}
 
int main(){
    
    std::cout << "sum({5}): " << sum({5}) << std::endl;
    std::cout << "sum({1, 2, 3}): " << sum({1, 2, 3}) << std::endl;
    std::cout << "sum({1, 2, 3, 4}): " << sum({1, 2, 3, 4})  << std::endl; 
     
}
