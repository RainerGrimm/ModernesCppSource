// jthreadJoinable.cpp

#include <iostream>
#include <thread>

int main() {
    
    std::cout << '\n';
    std::cout << std::boolalpha;
    
    std::jthread thr{[]{ std::cout << "Joinable std::thread" << '\n'; }};
    
    std::cout << "thr.joinable(): " << thr.joinable() << '\n';
    
    std::cout << '\n';
    
}