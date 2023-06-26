// monitorObject.cpp

#include <condition_variable>
#include <functional>
#include <queue>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>

class Monitor {
public:
    void lock() const {
        monitMutex.lock();
    }

    void unlock() const {
        monitMutex.unlock();
    }

    void notify_one() const noexcept {
        monitCond.notify_one();
    }

    template <typename Predicate>
    void wait(Predicate pred) const {
        std::unique_lock<std::mutex> monitLock(monitMutex);
        monitCond.wait(monitLock, pred);
    }
    
private:
    mutable std::mutex monitMutex;
    mutable std::condition_variable monitCond;
};

template <typename T>
class ThreadSafeQueue: public Monitor {
 public:
    void add(T val){ 
        lock();
        myQueue.push(val);
        unlock();
        notify_one();
    }
    
    T get(){ 
        wait( [this] { return ! myQueue.empty(); } );
        lock();
        auto val = myQueue.front();
        myQueue.pop();
        unlock();
        return val;
    }

private:
    std::queue<T> myQueue;
};


class Dice {
public:
    int operator()(){ return rand(); }
private:
    std::function<int()> rand = std::bind(std::uniform_int_distribution<>(1, 6), 
                                          std::default_random_engine());
};


int main(){
    
    std::cout << '\n';
    
    constexpr auto NumberThreads = 10;
    
    ThreadSafeQueue<int> safeQueue;

    auto addLambda = [&safeQueue](int val){ safeQueue.add(val);
                                            std::cout << val << " "
                                            << std::this_thread::get_id() << "; "; 
                                          }; 
    auto getLambda = [&safeQueue]{ safeQueue.get(); };

    std::vector<std::thread> addThreads(NumberThreads);
    Dice dice;
    for (auto& thr: addThreads) thr = std::thread(addLambda, dice() );

    std::vector<std::thread> getThreads(NumberThreads);
    for (auto& thr: getThreads) thr = std::thread(getLambda);

    for (auto& thr: addThreads) thr.join();
    for (auto& thr: getThreads) thr.join();
    
    std::cout << "\n\n";
     
}