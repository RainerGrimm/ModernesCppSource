#ifndef INCLUDED_PATTERNS_MONITOR3_MONITOR_HPP
#define INCLUDED_PATTERNS_MONITOR3_MONITOR_HPP

#include <algorithm>
#include <atomic>
#include <condition_variable>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <mutex>
#include <random>
#include <stdexcept>
#include <thread>
#include <tuple>
#include <vector>

namespace patterns::monitor3 {

template <typename T>
class Monitor {
public:
   struct UnlockAndNotify {
       std::mutex d_mutex;
       std::condition_variable d_condition;
   
       void lock() { d_mutex.lock(); }
       void unlock() { d_mutex.unlock(); d_condition.notify_one(); }
   };

private:
   mutable UnlockAndNotify d_combined;
   mutable T               d_data;

public:
   std::tuple<T&, std::unique_lock<UnlockAndNotify>> makeProducerLock() const {
       return { d_data, std::unique_lock{d_combined} };
   }

   template <typename PRED>
   std::tuple<T&, std::unique_lock<std::mutex>> makeConsumerLockWhen(PRED predicate) const {
       std::unique_lock lock{d_combined.d_mutex};
       d_combined.d_condition.wait(lock, [this, predicate]{ return predicate(d_data); });
       return { d_data, std::move(lock) };
   }
};

template <typename T>
class ThreadQueue {
   Monitor<std::deque<T>> d_monitor;

public:
   void add(T number) {
       auto[numberQueue, lock] = d_monitor.makeProducerLock();
       numberQueue.push_back(number);
   }

   T remove() {
       auto[numberQueue, lock] = d_monitor.makeConsumerLockWhen([](auto& numberQueue) { return !numberQueue.empty(); });
       const auto number = numberQueue.front();
       numberQueue.pop_front();
       return number;
   }
};
}

#endif

class Dice {
public:
    int operator()(){ return rand(); }
private:
    std::function<int()> rand = std::bind(std::uniform_int_distribution<>(1, 6), 
                                          std::default_random_engine());
};

int main(){
    
    std::cout << '\n';
    
    constexpr auto NumberThreads = 100;
    
    patterns::monitor3::ThreadQueue<int> safeQueue;                      // (7)

    auto addLambda = [&safeQueue](int val){ safeQueue.add(val);          // (8)
                                            std::cout << val << " "
                                            << std::this_thread::get_id() << "; "; 
                                          }; 
    auto getLambda = [&safeQueue]{ safeQueue.remove(); };  // (9)

    std::vector<std::thread> addThreads(NumberThreads);
    Dice dice;
    for (auto& thr: addThreads) thr = std::thread(addLambda, dice());

    std::vector<std::thread> getThreads(NumberThreads);
    for (auto& thr: getThreads) thr = std::thread(getLambda);

    for (auto& thr: addThreads) thr.join();
    for (auto& thr: getThreads) thr.join();
    
    std::cout << "\n\n";
     
}
