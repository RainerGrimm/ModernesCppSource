// conditionVariablePingPong.cpp

#include <condition_variable>
#include <iostream>
#include <thread>

bool dataReady= false;                                   // (3)

std::mutex mutex_;
std::condition_variable condVar1;
std::condition_variable condVar2;

int counter=0;
int COUNTLIMIT=50;

void setTrue(){                                           // (1)

  while(counter <= COUNTLIMIT){                           // (7)

    std::unique_lock<std::mutex> lck(mutex_);
    condVar1.wait(lck, []{return dataReady == false;});   // (4)
    dataReady= true;
    ++counter;                                            // (5)
    std::cout << dataReady << std::endl;
    condVar2.notify_one();                                // (6)

  }
}

void setFalse(){                                           // (2)

  while(counter < COUNTLIMIT){                             // (8)

    std::unique_lock<std::mutex> lck(mutex_);
    condVar2.wait(lck, []{return dataReady == true;});
    dataReady= false;
    std::cout << dataReady << std::endl;
    condVar1.notify_one();

  }

}

int main(){

  std::cout << std::boolalpha << std::endl;

  std::cout << "Begin: " << dataReady << std::endl;

  std::thread t1(setTrue);
  std::thread t2(setFalse);

  t1.join();
  t2.join();
  
  dataReady= false;
  std::cout << "End: " << dataReady << std::endl;

  std::cout << std::endl;
    
}
