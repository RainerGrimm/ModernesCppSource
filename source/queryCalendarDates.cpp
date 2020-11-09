// queryCalendarDates.cpp

#include "date.h"
#include <iostream>

int main() {

    using namespace date;

    std::cout << std::endl;

    auto now = std::chrono::system_clock::now();
    std::cout << "The current time is: " << now << " UTC\n"; 
    std::cout << "The current date is: " << floor<days>(now) << std::endl;
    std::cout << "The current date is: " << year_month_day{floor<days>(now)} << std::endl;
    std::cout << "The current date is: " << year_month_weekday{floor<days>(now)} << std::endl;

    std::cout << std::endl;

    
    auto currentDate = year_month_day(floor<days>(now));  
    auto currentYear = currentDate.year();
    std::cout << "The current year is " << currentYear << '\n';    
    auto currentMonth = currentDate.month();
    std::cout << "The current month is " << currentMonth << '\n'; 
    auto currentDay = currentDate.day();
    std::cout << "The current day is " << currentDay << '\n'; 

    std::cout << std::endl;
  
    auto hAfter = floor<std::chrono::hours>(now) - sys_days(January/1/currentYear);
    std::cout << "It has been " << hAfter << " since New Year!\n";  
    auto nextYear = currentDate.year() + years(1);
    auto nextNewYear = sys_days(January/1/nextYear);
    auto hBefore =  sys_days(January/1/nextYear) - floor<std::chrono::hours>(now); 
    std::cout << "It is " << hBefore << " before New Year!\n";

    std::cout << std::endl;

    std::cout << "It has been " << floor<days>(hAfter) << " since New Year!\n";    
    std::cout << "It is " << floor<days>(hBefore) << " before New Year!\n";
    
    std::cout << std::endl;
    
}