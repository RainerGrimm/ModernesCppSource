// ongoingOptimizationLock.cpp

#include <iostream>
#include <mutex>
#include <thread>

int x= 0;
int y= 0;

std::mutex mut;

void writing(){
  std::lock_guard<std::mutex> guard(mut);
  x= 2000;
  y= 11;
}

void reading(){
  std::lock_guard<std::mutex> guard(mut);
  std::cout << "y: " << y << " ";
  std::cout << "x: " << x << std::endl;
}

int main(){
  std::thread thread1(writing);
  std::thread thread2(reading);
  thread1.join();
  thread2.join();
};