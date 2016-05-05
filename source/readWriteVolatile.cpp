#include <iostream>
#include <thread>

volatile int x= 0;
volatile int y= 0;

void writing(){
  x= 2000;
  y= 11;
}

void reading(){ 
  std::cout << "y: " << y << " ";
  std::cout << "x: " << x << std::endl;
}

int main(){
  std::thread thread1(writing);
  std::thread thread2(reading);
  thread1.join();
  thread2.join();
};