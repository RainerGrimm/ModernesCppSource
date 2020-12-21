// conditionVariableAtomic.cpp

#include <atomic>
#include <iostream>
#include <thread>

std::atomic<bool> condAtomic{false};

void doTheWork(){
  std::cout << "Processing shared data." << std::endl;
}

void waitingForWork(){

    std::cout << "Worker: Waiting for work." << std::endl;
    condAtomic.wait(false);
    doTheWork();
    std::cout << "Work done." << std::endl;

}

void setDataReady(){

    std::cout << "Sender: Data is ready."  << std::endl;
    condAtomic.store(true);
    condAtomic.notify_one();

}

int main(){

  std::cout << std::endl;

  std::thread t1(waitingForWork);
  std::thread t2(setDataReady);

  t1.join();
  t2.join();

  std::cout << std::endl;
  
}

