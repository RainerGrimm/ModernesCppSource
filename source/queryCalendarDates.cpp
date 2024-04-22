// queryCalendarDates.cpp

#include <chrono>
#include <iostream>

int main() {

    std::cout << '\n';

    using std::chrono::floor;

    using std::chrono::January;

    using std::chrono::years;
    using std::chrono::days;
    using std::chrono::hours;

    using std::chrono::year_month_day;
    using std::chrono::year_month_weekday;

    using std::chrono::sys_days;

    auto now = std::chrono::system_clock::now();              
    std::cout << "The current time is: " << now << " UTC\n";                     // (1)   
    std::cout << "The current date is: " << floor<days>(now) << '\n';
    std::cout << "The current date is: " << year_month_day{floor<days>(now)} 
              << '\n';
    std::cout << "The current date is: " << year_month_weekday{floor<days>(now)} 
              << '\n';

    std::cout << '\n';

    
    auto currentDate = year_month_day(floor<days>(now));                         // (2)
    auto currentYear = currentDate.year();
    std::cout << "The current year is " << currentYear << '\n';    
    auto currentMonth = currentDate.month();
    std::cout << "The current month is " << currentMonth << '\n'; 
    auto currentDay = currentDate.day();
    std::cout << "The current day is " << currentDay << '\n'; 

    std::cout << '\n';
                                                               
    auto hAfter = floor<hours>(now) - sys_days(January/1/currentYear);           // (3)
    std::cout << "It has been " << hAfter << " since New Year!\n";  
    auto nextYear = currentDate.year() + years(1);             
    auto nextNewYear = sys_days(January/1/nextYear);
    auto hBefore =  sys_days(January/1/nextYear) - floor<hours>(now);            // (4)
    std::cout << "It is " << hBefore << " before New Year!\n";

    std::cout << '\n';
                                                            
    std::cout << "It has been " << floor<days>(hAfter) << " since New Year!\n";  // (5)
    std::cout << "It is " << floor<days>(hBefore) << " before New Year!\n";      // (6)
    
    std::cout << '\n';
    
}