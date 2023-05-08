// copiedValueDataRace.cpp

#include <functional>
#include <iostream>
#include <string>
#include <thread>

using namespace std::chrono_literals;

void byCopy(bool b){
    std::this_thread::sleep_for(1ms);
    std::cout << "byCopy: " << b << '\n';
}

void byReference(bool& b){
    std::this_thread::sleep_for(1ms);
    std::cout << "byReference: " << b << '\n';
}

void byConstReference(const bool& b){
    std::this_thread::sleep_for(1ms);
    std::cout << "byConstReference: " << b << '\n';
}

int main(){

    std::cout << std::boolalpha << '\n';

    bool shared{false};
    
    std::thread t1(byCopy, shared);
    std::thread t2(byReference, std::ref(shared));
    std::thread t3(byConstReference, std::cref(shared));
    
    shared = true;
    
    t1.join();
    t2.join();
    t3.join();

    std::cout << '\n';

}
