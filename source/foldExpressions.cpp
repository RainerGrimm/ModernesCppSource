// foldExpressions.cpp

#include <iostream>

template<class ...Args>
auto sum(Args... args) { 
    return (... + args); 
}
 
int main(){
    
    std::cout << "sum(5): " << sum(5) << std::endl;
    std::cout << "sum(1, 2, 3): " << sum(1, 2, 3) << std::endl;
    std::cout << "sum(1, 2, 3, 4): " << sum(1, 2, 3, 4)  << std::endl; 
    std::cout << "sum(1, 2, 3.5): " << sum(1, 2, 3.5) << std::endl;    

}
