// acquireReleaseWithoutWaiting.cpp

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::vector<int> mySharedWork;
std::atomic<bool> dataProduced(false);

void dataProducer(){
    mySharedWork={1,0,3};
    dataProduced.store(true, std::memory_order_release);
}

void dataConsumer(){
    dataProduced.load(std::memory_order_acquire);
    mySharedWork[1]= 2;
}

int main(){
    
  std::cout << std::endl;

  std::thread t1(dataConsumer);
  std::thread t2(dataProducer);

  t1.join();
  t2.join();
  
  for (auto v: mySharedWork){
      std::cout << v << " ";
  }
      
  std::cout << "\n\n";
  
}