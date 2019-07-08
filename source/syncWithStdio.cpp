// syncWithStdio.cpp

#include <iostream>
#include <cstdio>
 
int main(){
    
    std::ios::sync_with_stdio(false);

    std::cout << std::endl;
    
    std::cout << "1";
    std::printf("2");
    std::cout << "3";
    
    std::cout << std::endl;
    
}
