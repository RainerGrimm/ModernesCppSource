// threadSafeQueue.cpp

#ifndef INCLUDED_PATTERNS_MONITOR2_MONITOR_HPP
#define INCLUDED_PATTERNS_MONITOR2_MONITOR_HPP

#include <atomic>
#include <algorithm>
#include <condition_variable>
#include <deque>
#include <iterator>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <vector>


class Monitor {
public:
    struct UnlockAndNotify {
        std::mutex d_mutex;
        std::condition_variable d_condition;

        void lock() { d_mutex.lock(); }
        void unlock() { d_mutex.unlock(); d_condition.notify_one(); }
    };

private:
    UnlockAndNotify d_combined;

public:
    std::unique_lock<UnlockAndNotify> makeLockWithNotify() {
        return std::unique_lock{d_combined};
    }

    template <typename PRED>
    std::unique_lock<std::mutex> makeLockWithWait(PRED waitForCondition) {
        std::unique_lock lock{d_combined.d_mutex};
        d_combined.d_condition.wait(lock, waitForCondition);
        return lock;
    }
};

class ThreadQueue {
    Monitor d_monitor;
    std::deque<int> d_numberQueue;

    auto makeLockWhenNotEmpty() {
        return d_monitor.makeLockWithWait([this] { return !d_numberQueue.empty(); });
    }

public:
    void addNumber(int number) {
        const auto lock = d_monitor.makeLockWithNotify();
        d_numberQueue.push_back(number);
    }

    int removeNumber() {
        const auto lock = makeLockWhenNotEmpty();
        const auto number = d_numberQueue.front();
        d_numberQueue.pop_front();
        return number;
    }
};

#endif

int main() {
   ThreadQueue queue;
   std::atomic<int> sharedSum{};
   std::atomic<int> sharedCounter{};

   std::vector<std::jthread> threads;
   threads.reserve(200);
   std::generate_n(std::back_inserter(threads), 100, [&] {
       return std::jthread{[&] { sharedSum += queue.removeNumber(); }};
   });
   std::generate_n(std::back_inserter(threads), 100, [&] {
       return std::jthread{[&] { queue.addNumber(++sharedCounter); }};
   });

   threads.clear(); // wait for all threads to finish
   if (sharedSum.load() != 5050) {
       throw std::logic_error("Wrong result for sum of 1..100");
   }
}
