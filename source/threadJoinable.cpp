// threadJoinable.cpp

#include <iostream>
#include <thread>

int main(){
    
    std::cout << std::endl;
    std::cout << std::boolalpha;
    
    std::thread thr{[]{ std::cout << "Joinable std::thread" << std::endl; }};
    
    std::cout << "thr.joinable(): " << thr.joinable() << std::endl;
    
    std::cout << std::endl;
    
}
