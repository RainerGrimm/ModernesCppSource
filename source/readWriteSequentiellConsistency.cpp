#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> x{0};
std::atomic<int> y{0};

void writing(){  
  x.store(2000);  
  y.store(11);
}

void reading(){  
  std::cout << y.load() << " ";  
  std::cout << x.load() << std::endl;
}

int main(){
  std::thread thread1(writing);
  std::thread thread2(reading);
  thread1.join();
  thread2.join();
};