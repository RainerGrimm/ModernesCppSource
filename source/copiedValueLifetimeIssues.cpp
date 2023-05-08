// copiedValueLifetimeIssues.cpp

#include <iostream>
#include <string>
#include <thread>

void executeTwoThreads(){
    
    const std::string localString("local string");
    
    std::thread t1([localString]{
        std::cout << "Per Copy: " << localString << '\n';
    });
    
     std::thread t2([&localString]{
        std::cout << "Per Reference: " << localString << '\n';
    });
    
    t1.detach();
    t2.detach();
}
    
using namespace std::chrono_literals;

int main(){
    
    std::cout << '\n';
    
    executeTwoThreads();
    
    std::this_thread::sleep_for(1s);
    
    std::cout << '\n';
    
}
