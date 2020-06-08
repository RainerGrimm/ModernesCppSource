// clientTemplate1.cpp

#include <iostream>
import math;

int main() {
    
    std::cout << std::endl;     
   
    auto [val, message] = math::sum(2000, 11);
    std::cout << "math::sum(2000, 11): " << val << "; type: " << message << std::endl;
    
    auto [val1, message1] =  math::sum(2013.5, 0.5);
    std::cout << "math::sum(2013.5, 0.5): " << val1 << "; type: " << message1 << std::endl;
    
    auto [val2, message2] =  math::sum(2017, false);
    std::cout << "math::sum(2017, false): " << val2 << "; type: " << message2 << std::endl;
    
}
