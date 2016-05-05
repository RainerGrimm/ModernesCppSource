// atomicCondition.cpp

#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

std::vector<int> mySharedWork;
std::atomic<bool> dataReady(false);

void waitingForWork(){
    std::cout << "Waiting " << std::endl;
    while ( !dataReady.load() ){
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    mySharedWork[1]= 2;
    std::cout << "Work done " << std::endl;
}

void setDataReady(){
    mySharedWork={1,0,3};
    dataReady= true;
    std::cout << "Data prepared" << std::endl;
}

int main(){
    
  std::cout << std::endl;

  std::thread t1(waitingForWork);
  std::thread t2(setDataReady);

  t1.join();
  t2.join();
  
  for (auto v: mySharedWork){
      std::cout << v << " ";
  }
      
  
  std::cout << "\n\n";
  
}
