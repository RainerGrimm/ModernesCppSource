// nonsynchronized.cpp

#include <chrono>
#include <iostream>
#include <vector>
#include <thread>

using namespace std::chrono_literals;

int i= 0;

void increment(){
  synchronized{ 
    std::cout << ++i << " ,";
    std::this_thread::sleep_for(1ns);
  }
}

int main(){
  
  std::cout << std::endl;
    
  std::vector<std::thread> vecSyn(10);
  std::vector<std::thread> vecUnsyn(10);
    
  for(auto& thr: vecSyn)
    thr = std::thread([]{ for(int n = 0; n < 10; ++n) increment(); });
  for(auto& thr: vecUnsyn)
    thr = std::thread([]{ for(int n = 0; n < 10; ++n) std::cout << ++i << " ,"; });
    
  for(auto& thr: vecSyn) thr.join();
  for(auto& thr: vecUnsyn) thr.join();
  
  std::cout << "\n\n";
  
}
