// synchronized.cpp

#include <iostream>
#include <vector>
#include <thread>

int i= 0;

void increment(){
  synchronized{ 
    std::cout << ++i << " ,";
  }
}

int main(){
  
  std::cout << std::endl;
    
  std::vector<std::thread> vecSyn(10);
  for(auto& thr: vecSyn)
    thr = std::thread([]{ for(int n = 0; n < 10; ++n) increment(); });
  for(auto& thr: vecSyn) thr.join();
  
  std::cout << "\n\n";
  
}
