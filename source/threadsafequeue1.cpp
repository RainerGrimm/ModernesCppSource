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
    using Lock = std::unique_lock<std::mutex>;
    [[nodiscard]] Lock receiveGuard() {
        return Lock(monitMutex);
    }

    template <typename Predicate>
    void wait(Lock& kerberos, Predicate pred) {
        monitCond.wait(kerberos, pred);
    }

    class SendGuard {
        friend class Monitor;
        using deleter = decltype([](auto* cond){ cond->notify_one(); });
        std::unique_ptr<std::condition_variable, deleter> notifier;
        std::lock_guard<std::mutex> kerberos;
        SendGuard(auto& mutex, auto& cond): notifier(&cond), kerberos(mutex) {}
    };

    SendGuard sendGuard() { return {monitMutex, monitCond}; }
    
private:
    mutable std::mutex monitMutex;
    mutable std::condition_variable monitCond;
};

template <typename T>                                  // (1)
class ThreadSafeQueue: public Monitor {
 public:
    void add(T val){ 
        auto kerberos = sendGuard();
        myQueue.push(val);                             // (6)
    }
    
    T get(){ 
        auto kerberos = receiveGuard();
        wait(kerberos, [this] { return ! myQueue.empty(); } );  // (2)
        auto val = myQueue.front();                    // (4)
        myQueue.pop();                                 // (5)
        return val;
    }

private:
    std::queue<T> myQueue;                            // (3)
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
    
    constexpr auto NumberThreads = 100;
    
    ThreadSafeQueue<int> safeQueue;                      // (7)

    auto addLambda = [&safeQueue](int val){ safeQueue.add(val);          // (8)
                                            std::cout << val << " "
                                            << std::this_thread::get_id() << "; "; 
                                          }; 
    auto getLambda = [&safeQueue]{ safeQueue.get(); };  // (9)

    std::vector<std::thread> addThreads(NumberThreads);
    Dice dice;
    for (auto& thr: addThreads) thr = std::thread(addLambda, dice());

    std::vector<std::thread> getThreads(NumberThreads);
    for (auto& thr: getThreads) thr = std::thread(getLambda);

    for (auto& thr: addThreads) thr.join();
    for (auto& thr: getThreads) thr.join();
    
    std::cout << "\n\n";
     
}
