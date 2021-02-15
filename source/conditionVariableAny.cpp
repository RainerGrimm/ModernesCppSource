// conditionVariableAny.cpp

#include <condition_variable>
#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

using namespace std::literals;

std::mutex mutex_;
std::condition_variable_any condVar;

bool dataReady;

void receiver(std::stop_token stopToken) {

    std::cout << "Waiting" << '\n';

    std::unique_lock<std::mutex> lck(mutex_);
    bool ret = condVar.wait(lck, stopToken, []{return dataReady;});
    if (ret){
        std::cout << "Notification received: " << '\n';
    }
    else{
         std::cout << "Stop request received" << '\n';
    }
}

void sender() {

    std::this_thread::sleep_for(5ms);
    {
        std::lock_guard<std::mutex> lck(mutex_);
        dataReady = true;
        std::cout << "Send notification"  << '\n';
    }
    condVar.notify_one();

}

int main(){

  std::cout << '\n';

  std::jthread t1(receiver);
  std::jthread t2(sender);
  
  t1.request_stop();

  t1.join();
  t2.join();

  std::cout << '\n';
  
}