// localTime.cpp

#include "date/tz.h"
#include <iostream>

int main() {

    std::cout << std::endl;

    using namespace date;
 
    std::cout << "UTC  time" << std::endl;
    auto utcTime = std::chrono::system_clock::now();
    std::cout << "  " << utcTime << std::endl;
    std::cout << "  " << date::floor<std::chrono::seconds>(utcTime) << '\n':

    std::cout << std::endl;
    
    std::cout << "Local time" << std::endl;
    auto localTime = date::make_zoned(date::current_zone(), utcTime);
    std::cout << "  " << localTime << std::endl;
    std::cout << "  " << date::floor<std::chrono::seconds>(localTime.get_local_time()) 
               << std::endl;

    auto offset = localTime.get_info().offset;
    std::cout << "  UTC offset: "  << offset << std::endl;

    std::cout << std::endl;

}