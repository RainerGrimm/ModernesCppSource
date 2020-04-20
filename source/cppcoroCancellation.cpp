// cppcoroCancellation.cpp

#include <chrono>
#include <iostream>
#include <future>

#include <cppcoro/cancellation_token.hpp>
#include <cppcoro/cancellation_source.hpp>

using namespace std::chrono_literals; 

int main() {
    
    std::cout << std::endl;
    
    cppcoro::cancellation_source canSource;
    cppcoro::cancellation_token canToken = canSource.token();

    auto cancelSender = std::async([&canSource] { 
        std::this_thread::sleep_for(2s);
        canSource.request_cancellation();
        std::cout << "canSource.request_cancellation() " << std::endl;
    });
        
    auto cancelReceiver = std::async([&canToken] { 
        while(true) {
            std::cout << "Wait for cancellation request" << std::endl;
             std::this_thread::sleep_for(200ms);
            if (canToken.is_cancellation_requested()) return;
        }
    });

    cancelSender.get(), cancelReceiver.get();
    
    std::cout << std::endl;

}
