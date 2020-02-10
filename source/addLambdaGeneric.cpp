// addLambdaGeneric.cpp

#include <iostream>

auto addLambda = [](auto fir, auto sec){ return fir + sec; }; 

template <typename T, typename T2>                            
auto addTemplate(T fir, T2 sec){ return fir + sec; }


int main(){
    
    std::cout << addLambda(2000, 11.5);    // 2011.5
    std::cout << addTemplate(2000, 11.5);  // 2011.5
    
}
