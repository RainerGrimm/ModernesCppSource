// variadicFold.cpp

#include <iostream>

template<typename T, typename... Args>
T sumVar(T first, Args... args) {
  return first + sumVar(args...);
}

template<class ...Args>
auto sumFold(Args... args) { 
    return (... + args); 
}
 
int main(){

    std::cout << "sumVar(5): " << sumVar(5) << std::endl;
    std::cout << "sumVar(1, 2, 3): " << sumVar(1, 2, 3) << std::endl;
    std::cout << "sumVar(1, 2, 3, 4): " << sumVar(1, 2, 3, 4)  << std::endl; 
    std::cout << "sumVar(1, 2, 3.5): " << sumVar(1, 2, 3.5) << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "sumFold(5): " << sumFold(5) << std::endl;
    std::cout << "sumFold(1, 2, 3): " << sumFold(1, 2, 3) << std::endl;
    std::cout << "sumFold(1, 2, 3, 4): " << sumFold(1, 2, 3, 4)  << std::endl; 
    std::cout << "sumFold(1, 2, 3.5): " << sumFold(1, 2, 3.5) << std::endl;    

}