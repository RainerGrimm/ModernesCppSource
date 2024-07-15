// signalStopRequests.cpp

#include <iostream>
#include <thread>
#include <future>

using namespace std::literals;

void function1(std::stop_token stopToken, const std::string& str){
    std::this_thread::sleep_for(1s);
    if (stopToken.stop_requested()) std::cout << str << ": Stop requested\n";
}

void function2(std::promise<void> prom, 
               std::stop_token stopToken, const std::string& str) {
    std::this_thread::sleep_for(1s);
    std::stop_callback callBack(stopToken, [&str] { 
        std::cout << str << ": Stop requested\n"; 
    });
    prom.set_value();
}

int main() {

    std::cout << '\n';

    std::stop_source stopSource;                                                // (1)

    std::stop_token stopToken = std::stop_token(stopSource.get_token());        // (2)

    std::thread thr1 = std::thread(function1, stopToken, "std::thread");        // (3)
    
    std::jthread jthr = std::jthread(function1, stopToken, "std::jthread");     // (4)
    
    auto fut1 = std::async([stopToken] {                                        // (5)
        std::this_thread::sleep_for(1s);
        if (stopToken.stop_requested()) std::cout << "std::async: Stop requested\n";
    });

    std::promise<void> prom;                                                    // (6)
    auto fut2 = prom.get_future();
    std::thread thr2(function2, std::move(prom), stopToken, "std::promise");

    stopSource.request_stop();                                                  // (7)
    if (stopToken.stop_requested()) std::cout << "main: Stop requested\n";      // (8)

    thr1.join();
    thr2.join();

    std::cout << '\n';

}