// blockJoin.cpp

#include <iostream>
#include <mutex>
#include <thread>

std::mutex coutMutex;

int main(){

  std::thread t([]{
    std::cout << "Still waiting ..." << std::endl;
    std::lock_guard<std::mutex> lockGuard(coutMutex);
    std::cout << std::this_thread::get_id() << std::endl;
    }
  );

  {
    std::lock_guard<std::mutex> lockGuard(coutMutex);
    std::cout << std::this_thread::get_id() << std::endl;
    t.join();
  }

}