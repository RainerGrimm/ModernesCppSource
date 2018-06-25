// conditionVariableAtomic.cpp

#include <atomic>
#include <condition_variable>
#include <iostream>
#include <thread>

std::mutex mutex_;
std::condition_variable condVar;

std::atomic<bool> dataReady{false};

void waitingForWork(){
    std::cout << "Waiting " << std::endl;
    std::unique_lock<std::mutex> lck(mutex_);
    condVar.wait(lck, []{ return dataReady.load(); });   // (1)
    std::cout << "Running " << std::endl;
}

void setDataReady(){
    dataReady = true;
    std::cout << "Data prepared" << std::endl;
    condVar.notify_one();
}

int main(){
    
  std::cout << std::endl;

  std::thread t1(waitingForWork);
  std::thread t2(setDataReady);

  t1.join();
  t2.join();
  
  std::cout << std::endl;
  
}
