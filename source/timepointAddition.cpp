// timepointAddition.cpp

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std::chrono;

std::string timePointAsString(const time_point<system_clock>& timePoint){
    std::time_t tp= system_clock::to_time_t(timePoint);
    return std::asctime(std::gmtime(&tp));
}

int main(){  
    
    std::cout << std::endl;
    
    time_point<system_clock> nowTimePoint= system_clock::now();
    std::cout << "Now:              " << timePointAsString(nowTimePoint) << std::endl;
     
    auto thousandYears=  hours(24*365*1000);
    time_point<system_clock>  historyTimePoint= nowTimePoint - thousandYears;
    std::cout << "Now - 1000 years: " << timePointAsString(historyTimePoint) << std::endl;
    
    time_point<system_clock>  futureTimePoint= nowTimePoint + thousandYears;
    std::cout << "Now + 1000 years: " << timePointAsString(futureTimePoint) << std::endl;
     
}