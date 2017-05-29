// conditionVariableBlock.cpp

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

std::mutex mutex_;
std::condition_variable condVar;

bool dataReady;


void waitingForWork(){

    std::cout << "Worker: Waiting for work." << std::endl;

    std::unique_lock<std::mutex> lck(mutex_);
    condVar.wait(lck);                           // 3
    // do the work
    std::cout << "Work done." << std::endl;

}

void setDataReady(){

    std::cout << "Sender: Data is ready."  << std::endl;
    condVar.notify_one();                        // 1

}

int main(){

  std::cout << std::endl;

  std::thread t1(setDataReady);
  std::thread t2(waitingForWork);                // 2

  t1.join();
  t2.join();

  std::cout << std::endl;
  
}
