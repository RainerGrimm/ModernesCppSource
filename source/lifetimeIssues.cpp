// lifetimeIssues.cpp

#include <iostream>
#include <string>
#include <thread>

int main(){
    
  std::cout << "Begin:" << std::endl;            // 2    

  std::string mess{"Child thread"};

  std::thread t([&mess]{ std::cout << mess << std::endl;});
  t.detach();                                    // 1
  
  std::cout << "End:" << std::endl;              // 3

}