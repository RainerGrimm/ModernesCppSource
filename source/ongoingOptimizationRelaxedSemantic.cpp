// ongoingOptimizationRelaxedSemantic.cpp

#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> x{0};
std::atomic<int> y{0};

void writing(){  
  x.store(2000,std::memory_order_relaxed);  
  y.store(11,std::memory_order_relaxed);
}

void reading(){  
  std::cout << y.load(std::memory_order_relaxed) << " ";  
  std::cout << x.load(std::memory_order_relaxed) << std::endl;
}

int main(){
  std::thread thread1(writing);
  std::thread thread2(reading);
  thread1.join();
  thread2.join();
};