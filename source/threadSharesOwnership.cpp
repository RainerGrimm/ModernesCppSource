// threadSharesOwnership.cpp

#include <iostream>
#include <thread>

using namespace std::literals::chrono_literals;

struct MyInt{
  int val{2017};
  ~MyInt(){
    std::cout << "Good Bye" << std::endl;
  }
};

void showNumber(MyInt* myInt){
    std::cout << myInt->val << std::endl;
}

void threadCreator(){
    MyInt* tmpInt= new MyInt; 
    
    std::thread t1(showNumber, tmpInt);
    std::thread t2(showNumber, tmpInt);
    
    t1.detach();
    t2.detach();
}

int main(){
    
    std::cout << std::endl;
    
    threadCreator();
    std::this_thread::sleep_for(1s);
    
    std::cout << std::endl;
    
}
