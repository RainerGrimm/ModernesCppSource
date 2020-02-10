// addUnconstrainedConstrained.cpp

#include <concepts>
#include <iostream>

auto addUnconstrained(auto fir, auto sec){
     return fir + sec;
}

std::floating_point auto addConstrained(std::integral auto fir, 
                                        std::floating_point auto sec){
     return fir + sec;
}

int main(){
    
    std::cout << addUnconstrained(2000, 11.5); // 2011.5
    std::cout << addConstrained(2000, 11.5);   // 2011.5
    
}
