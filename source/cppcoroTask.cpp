// cppcoroTask.cpp

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include <cppcoro/sync_wait.hpp>
#include <cppcoro/task.hpp>

using std::chrono::high_resolution_clock;
using std::chrono::time_point;
using std::chrono::duration;

using namespace std::chrono_literals; // 1s
   
auto getTimeSince(const time_point<high_resolution_clock>& start) {
    
    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    return elapsed.count();
    
}

cppcoro::task<> third(const time_point<high_resolution_clock>& start) {
    
    std::this_thread::sleep_for(1s);
    std::cout << "Third waited " << getTimeSince(start) << " seconds." << std::endl;

    co_return;
        
}

cppcoro::task<> second(const time_point<high_resolution_clock>& start) {
    
    auto thi = third(start);
    std::this_thread::sleep_for(1s);
    co_await thi;
    
    std::cout << "Second waited " <<  getTimeSince(start) << " seconds." << std::endl;
    
}

cppcoro::task<> first(const time_point<high_resolution_clock>& start) {
    
    auto sec = second(start);
    std::this_thread::sleep_for(1s);
    co_await sec;
    
    std::cout << "First waited " <<  getTimeSince(start)  << " seconds." << std::endl;
    
}

int main() {
    
    std::cout << std::endl;
    
    auto start = high_resolution_clock::now();
    cppcoro::sync_wait(first(start));
    
    std::cout << "Main waited " <<  getTimeSince(start) << " seconds." << std::endl;
    
    std::cout << std::endl;

}
