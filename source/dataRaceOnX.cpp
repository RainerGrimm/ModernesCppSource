// dataRaceOnX.cpp

#include <atomic>
#include <iostream>
#include <thread>

int x = 0;
std::atomic<int> y{0};

void writing(){  
  x = 2000;                                              // (1)
  y.store(11, std::memory_order_release);                // (2)
}

void reading(){  
  std::cout << y.load(std::memory_order_acquire) << " "; // (2)
  std::cout << x << std::endl;                           // (1)
}

int main(){

    std::thread thread1(writing);
    std::thread thread2(reading);

    thread1.join();
    thread2.join();
    
}
