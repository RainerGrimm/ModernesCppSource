// sysDays.cpp

#include <chrono>
#include <iostream>
 
int main() {

    std::cout << '\n';

    using std::chrono::last;

    using std::chrono::year;
    using std::chrono::sys_days;

    using std::chrono::March;
    using std::chrono::February;

    using std::chrono::Monday;
    using std::chrono::Thursday;

    constexpr auto yearMonthDayLast{year(2010)/March/last};               // (1)
    std::cout << "sys_days(yearMonthDayLast): " 
              << sys_days(yearMonthDayLast)  <<  '\n';

    constexpr auto yearMonthWeekday{year(2020)/March/Thursday[2]};
    std::cout << "sys_days(yearMonthWeekday): " 
              <<  sys_days(yearMonthWeekday) << '\n';

    constexpr auto yearMonthWeekdayLast{year(2010)/March/Monday[last]};
    std::cout << "sys_days(yearMonthWeekdayLast): " 
              << sys_days(yearMonthWeekdayLast) << '\n';

    std::cout << '\n';

    constexpr auto leapDate{year(2012)/February/last};               
    std::cout << "sys_days(leapDate): " << sys_days(leapDate) << '\n';    // (2)

    constexpr auto noLeapDate{year(2013)/February/last};             
    std::cout << "sys_day(noLeapDate): " << sys_days(noLeapDate) << '\n'; // (3)

    std::cout << '\n';

}  