// cppcoroMutex.cpp

#include <cppcoro/async_mutex.hpp>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/task.hpp>

#include <iostream>
#include <thread>
#include <vector>


cppcoro::async_mutex mutex;

int sum{};                                                                  // (2)

cppcoro::task<> addToSum(int num) {
    cppcoro::async_mutex_lock lockSum = co_await mutex.scoped_lock_async(); // (3)  
    sum += num;
  
}                                                                           // (4)

int main() {
    
    std::cout << std::endl;
    
    std::vector<std::thread> vec(10);                                       // (1)
    
    for(auto& thr: vec) {
        thr = std::thread([]{ for(int n = 0; n < 10; ++n) cppcoro::sync_wait(addToSum(n)); } );
    }
    
    for(auto& thr: vec) thr.join();
    
    std::cout << "sum: " << sum << std::endl;
    
    std::cout << std::endl;
    
}
