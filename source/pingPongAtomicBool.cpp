// pingPongAtomicBool.cpp

#include <iostream>
#include <atomic>
#include <thread>

std::atomic<bool> atomicBool{};

std::atomic<int> counter{};
constexpr int countlimit = 1'000'000;

void ping() {
    while(counter <= countlimit) {
        atomicBool.wait(true);
        atomicBool.store(true);

        ++counter;
        
        atomicBool.notify_one();
    }
}

void pong() {
    while(counter < countlimit) {
        atomicBool.wait(false);
        atomicBool.store(false);
        atomicBool.notify_one();
    }
}

int main() {

    std::cout << std::boolalpha << std::endl;

    std::cout << "atomicBool.is_lock_free(): " 
              << atomicBool.is_lock_free()  << std::endl;

    std::cout << std::endl;

    auto start = std::chrono::system_clock::now();

    atomicBool.store(true);
    std::thread t1(ping);
    std::thread t2(pong);

    t1.join();
    t2.join();

    std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
    std::cout << "Duration: " << dur.count() << " seconds" << std::endl;

}


