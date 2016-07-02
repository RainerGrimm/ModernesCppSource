// producerConsumer.cpp

#include <atomic>
#include <iostream>
#include <string>
#include <thread>

std::string work;
std::atomic<bool> ready(false);

void consumer(){
  while(!ready.load()){}
  std::cout<< work << std::endl;    
}

void producer(){
  work= "done";
  ready=true; 
}

int main(){
  std::thread prod(producer);
  std::thread con(consumer);
  prod.join(); 
  con.join();
}