// invokeCallbacks.cpp

#include <chrono>
#include <iostream>
#include <thread>

using namespace std::literals;

void func(std::stop_token stopToken) {
    std::this_thread::sleep_for(100ms);
    for (int i = 0; i <= 9; ++i) {
       std::stop_callback cb(stopToken, [i] { std::cout << i; });
    }
    std::cout << '\n';
}

int main() {
    
    std::cout << '\n';
    
    std::jthread thr1 = std::jthread(func);
    std::jthread thr2 = std::jthread(func);
    thr1.request_stop();
    thr2.request_stop();

    std::cout << '\n';
    
}