// createCalendar.cpp

#include <iostream>
#include "date.h"
 
int main() {

    std::cout << std::endl;
    
    using namespace date;

    constexpr auto yearMonthDay{year(1940)/month(6)/day(26)};
    std::cout << yearMonthDay << " ";
    std::cout << date::year_month_day(1940_y, June, 26_d) << std::endl;

    std::cout << std::endl;

    constexpr auto yearMonthDayLast{year(2010)/March/last};
    std::cout << yearMonthDayLast << " ";
    std::cout << date::year_month_day_last(2010_y, month_day_last(month(3))) <<  std::endl;

    constexpr auto yearMonthWeekday{year(2020)/March/Thursday[2]};
    std::cout << yearMonthWeekday << " ";
    std::cout << date::year_month_weekday(2020_y, month(March), Thursday[2]) <<  std::endl;

    constexpr auto yearMonthWeekdayLast{year(2010)/March/Monday[last]};
    std::cout << yearMonthWeekdayLast << " ";
    std::cout << date::year_month_weekday_last(2010_y, month(March), weekday_last(Monday)) <<  std::endl;

    std::cout << std::endl;

    constexpr auto day_{day(19)};
    std::cout << day_  << " ";
    std::cout << date::day(19) << std::endl;

    constexpr auto month_{month(1)};
    std::cout << month_  << " ";
    std::cout << date::month(1) << std::endl;

    constexpr auto year_{year(1988)};
    std::cout << year_  << " ";
    std::cout << date::year(1988) << std::endl;

    constexpr auto weekday_{weekday(5)};
    std::cout << weekday_  << " ";
    std::cout << date::weekday(5) << std::endl;
 
    constexpr auto yearMonth{year(1988)/1};
    std::cout << yearMonth  << " ";
    std::cout << date::year_month(year(1988), January) << std::endl;
 
    constexpr auto monthDay{10/day(22)};
    std::cout << monthDay <<  " ";
    std::cout << date::month_day(October, day(22)) << std::endl;

    constexpr auto monthDayLast{June/last};
    std::cout << monthDayLast << " ";
    std::cout << date::month_day_last(month(6)) << std::endl;
 
    constexpr auto monthWeekday{2/Monday[3]};
    std::cout << monthWeekday << " ";
    std::cout << date::month_weekday(February, Monday[3]) << std::endl;
 
    constexpr auto monthWeekDayLast{June/Sunday[last]};
    std::cout << monthWeekDayLast << " ";
    std::cout << date::month_weekday_last(June, weekday_last(Sunday)) << std::endl;

    std::cout << std::endl;

}