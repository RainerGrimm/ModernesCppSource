// cppcoroTask2.cpp

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include <cppcoro/sync_wait.hpp>
#include <cppcoro/task.hpp>

using std::chrono::high_resolution_clock;
using std::chrono::time_point;
using std::chrono::duration;

using namespace std::chrono_literals;

auto getTimeSince(const time_point<::high_resolution_clock>& start) {
    
    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    return elapsed.count();
    
}

cppcoro::task<> third(const time_point<high_resolution_clock>& start) {
    
    std::cout << "Third waited " << getTimeSince(start) << " seconds." << std::endl;
    std::this_thread::sleep_for(1s);
    co_return;
        
}


cppcoro::task<> second(const time_point<high_resolution_clock>& start) {
    
    auto thi = third(start);
    co_await thi;
    
    std::cout << "Second waited " <<  getTimeSince(start) << " seconds." << std::endl;
    std::this_thread::sleep_for(1s);
    
}

cppcoro::task<> first(const time_point<high_resolution_clock>& start) {
    
    auto sec = second(start);
    co_await sec;
    
    std::cout << "First waited " <<  getTimeSince(start)  << " seconds." << std::endl;
    std::this_thread::sleep_for(1s);
    
}

int main() {
    
    std::cout << std::endl;
 
    auto start = ::high_resolution_clock::now();
    
    cppcoro::sync_wait(first(start));
    
    std::cout << "Main waited " <<  getTimeSince(start) << " seconds." << std::endl;
    
    std::cout << std::endl;

}
