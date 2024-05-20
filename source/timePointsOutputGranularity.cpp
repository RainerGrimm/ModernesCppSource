// timePointsOutputGranularity.cpp

#include <chrono>
#include <iostream>

int main() {

    std::cout << '\n';

    auto now = std::chrono::system_clock::now();
    
    auto zonedTime = std::chrono::zoned_time(std::chrono::current_zone(), now); 
    auto localTime = zonedTime.get_local_time();

    std::cout << "local_time:                                               " 
              << localTime << '\n';

    std::cout << "std::chrono::floor<std::chrono::microseconds>(localTime): " 
              << std::chrono::floor<std::chrono::microseconds>(localTime) << '\n'; 

    std::cout << "std::chrono::floor<std::chrono::milliseconds>(localTime): "
              << std::chrono::floor<std::chrono::milliseconds>(localTime) << '\n';

    std::cout << "std::chrono::floor<std::chrono::seconds>(localTime):      "
              << std::chrono::floor<std::chrono::seconds>(localTime) << '\n';
    
    std::cout << "std::chrono::floor<std::chrono::minutes>(localTime):      "
              << std::chrono::floor<std::chrono::minutes>(localTime) << '\n';

    std::cout << "std::chrono::floor<std::chrono::hours>(localTime):        " 
              << std::chrono::floor<std::chrono::hours>(localTime) << '\n';

    std::cout << "std::chrono::floor<std::chrono::days>(localTime):         "
              << std::chrono::floor<std::chrono::days>(localTime) << '\n';

    std::cout << "std::chrono::floor<std::chrono::weeks>(localTime):        "
              << std::chrono::floor<std::chrono::weeks>(localTime) << '\n';

    // std::cout << std::chrono::floor<std::chrono::months>(localTime) << '\n';    ERROR
    // std::cout << std::chrono::floor<std::chrono::years>(localTime) << '\n';     ERROR

    std::cout << '\n';

}