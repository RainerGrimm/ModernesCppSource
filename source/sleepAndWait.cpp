// sleepAndWait.cpp

#include <utility>
#include <iostream>
#include <future>
#include <thread>
#include <utility>

std::mutex coutMutex;

long double getDifference(const std::chrono::steady_clock::time_point& tp1,const std::chrono::steady_clock::time_point& tp2){
    auto diff= tp2- tp1;
    auto res= std::chrono::duration <double, std::milli> (diff).count();
    return res;
}

int producer(std::promise<int>&& prom){
    std::cout << "PRODUCING THE VALUE 2011\n\n"; 
    std::this_thread::sleep_for(std::chrono::seconds(5));
    prom.set_value(2011);
}

void consumer(std::shared_future<int> fut,std::chrono::steady_clock::duration dur){
    auto start = std::chrono::steady_clock::now();
    std::future_status status= fut.wait_until(std::chrono::steady_clock::now() + dur);
    if ( status == std::future_status::ready ){
        std::lock_guard<std::mutex> lockCout(coutMutex);
        std::cout << std::this_thread::get_id() << " ready => Result: " << fut.get() << std::endl;
    }
    else{
        std::lock_guard<std::mutex> lockCout(coutMutex);
        std::cout << std::this_thread::get_id() << " stopped waiting." << std::endl;
    }
    auto end= std::chrono::steady_clock::now();
    std::lock_guard<std::mutex> lockCout(coutMutex);
    std::cout << std::this_thread::get_id() << " waiting time: " << getDifference(start,end) << " ms" << std::endl;
}

void consumePeriodically(std::shared_future<int> fut){
    auto start = std::chrono::steady_clock::now();
    std::future_status status;
    do {
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        status = fut.wait_for(std::chrono::seconds(0));
        if (status == std::future_status::timeout) {
            std::lock_guard<std::mutex> lockCout(coutMutex);
            std::cout << "     " << std::this_thread::get_id() << " still waiting." << std::endl;
        }
        if (status == std::future_status::ready) {
            std::lock_guard<std::mutex> lockCout(coutMutex);
            std::cout << "     " << std::this_thread::get_id() << " waiting done => Result: " << fut.get() << std::endl;
        }
    } while (status != std::future_status::ready); 
    auto end= std::chrono::steady_clock::now();
    std::lock_guard<std::mutex> lockCout(coutMutex);
    std::cout << "     " << std::this_thread::get_id() << " waiting time: " << getDifference(start,end) << " ms" << std::endl;
}

void consumeWithBackoff(std::shared_future<int> fut){
    auto start = std::chrono::steady_clock::now();
    std::future_status status;
    auto dur= std::chrono::milliseconds(1);
    do {
        std::this_thread::sleep_for(dur);
        status = fut.wait_for(std::chrono::seconds(0));
        dur *= 2;
        if (status == std::future_status::timeout) {
            std::lock_guard<std::mutex> lockCout(coutMutex);
            std::cout << "         " << std::this_thread::get_id() << " still waiting." << std::endl;
        }
        if (status == std::future_status::ready) {
            std::lock_guard<std::mutex> lockCout(coutMutex);
            std::cout << "         " << std::this_thread::get_id() << " waiting done => Result: " << fut.get() << std::endl;
        }
    } while (status != std::future_status::ready);
    auto end= std::chrono::steady_clock::now();
    std::lock_guard<std::mutex> lockCout(coutMutex);
    std::cout << "         " << std::this_thread::get_id() << " waiting time: " << getDifference(start,end) << " ms" << std::endl;
}

int main(){
    
    std::cout << std::endl;

    std::promise<int> prom;
    std::shared_future<int> future= prom.get_future();
    std::thread producerThread(producer,std::move(prom));
    
    std::thread consumerThread1(consumer,future,std::chrono::seconds(4));
    std::thread consumerThread2(consumer,future,std::chrono::seconds(20));
    std::thread consumerThread3(consumePeriodically,future);
    std::thread consumerThread4(consumeWithBackoff,future);
    
    consumerThread1.join();
    consumerThread2.join();
    consumerThread3.join();
    consumerThread4.join();
    producerThread.join();
    
    std::cout << std::endl;

}