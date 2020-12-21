// threadSynchronisationConditionVariable.cpp

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mutex_;
std::condition_variable condVar;

std::vector<int> myVec{};

void prepareWork() {

    {
        std::lock_guard<std::mutex> lck(mutex_);
        myVec.insert(myVec.end(), {0, 1, 0, 3});
    }
    std::cout << "Sender: Data prepared."  << std::endl;
    condVar.notify_one();
}

void completeWork() {

    std::cout << "Worker: Waiting for data." << std::endl;
    std::unique_lock<std::mutex> lck(mutex_);
    condVar.wait(lck, [] { return not myVec.empty(); });
    myVec[2] = 2;
    std::cout << "Waiter: Complete the work." << std::endl;
    for (auto i: myVec) std::cout << i << " ";
    std::cout << std::endl;
    
}

int main() {

    std::cout << std::endl;

    std::thread t1(prepareWork);
    std::thread t2(completeWork);

    t1.join();
    t2.join();

    std::cout << std::endl;
  
}

