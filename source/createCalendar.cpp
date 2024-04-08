// createCalendar.cpp

#include <chrono>
#include <iostream>
 
int main() {

    std::cout << '\n';

    using namespace std::chrono_literals; 

    using std::chrono::last;

    using std::chrono::year;
    using std::chrono::month;
    using std::chrono::day;

    using std::chrono::year_month;
    using std::chrono::year_month_day;
    using std::chrono::year_month_day_last;
    using std::chrono::year_month_weekday;
    using std::chrono::year_month_weekday_last;
    using std::chrono::month_weekday;
    using std::chrono::month_weekday_last;
    using std::chrono::month_day;
    using std::chrono::month_day_last;
    using std::chrono::weekday_last;
    using std::chrono::weekday;

    using std::chrono::January;
    using std::chrono::February;
    using std::chrono::June;
    using std::chrono::March;
    using std::chrono::October;

    using std::chrono::Monday;
    using std::chrono::Thursday;
    using std::chrono::Sunday;

    constexpr auto yearMonthDay{year(1940)/month(6)/day(26)};                // (1)
    std::cout << yearMonthDay << " ";
    std::cout << year_month_day(1940y, June, 26d) << '\n';                   // (2)

    std::cout << '\n';

    constexpr auto yearMonthDayLast{year(2010)/March/last};                  // (3)
    std::cout << yearMonthDayLast << " ";
    std::cout << year_month_day_last(2010y, month_day_last(month(3))) << '\n';

    constexpr auto yearMonthWeekday{year(2020)/March/Thursday[2]};            // (4)
    std::cout << yearMonthWeekday << " ";
    std::cout << year_month_weekday(2020y, month(March), Thursday[2]) << '\n';

    constexpr auto yearMonthWeekdayLast{year(2010)/March/Monday[last]};        //(5)
    std::cout << yearMonthWeekdayLast << " ";
    std::cout << year_month_weekday_last(2010y, month(March), weekday_last(Monday));

    std::cout << "\n\n";

    constexpr auto day_{day(19)};     // (6)         
    std::cout << day_  << " ";
    std::cout << day(19) << '\n';

    constexpr auto month_{month(1)};  // (7)     
    std::cout << month_  << " ";
    std::cout << month(1) << '\n';

    constexpr auto year_{year(1988)}; // (8)    
    std::cout << year_  << " ";
    std::cout << year(1988) << '\n';

    constexpr auto weekday_{weekday(5)};
    std::cout << weekday_  << " ";
    std::cout << weekday(5) << '\n';
 
    constexpr auto yearMonth{year(1988)/1};
    std::cout << yearMonth  << " ";
    std::cout << year_month(year(1988), January) << '\n';
 
    constexpr auto monthDay{10/day(22)};
    std::cout << monthDay <<  " ";
    std::cout << month_day(October, day(22)) << '\n';

    constexpr auto monthDayLast{June/last};
    std::cout << monthDayLast << " ";
    std::cout << month_day_last(month(6)) << '\n';
 
    constexpr auto monthWeekday{2/Monday[3]};
    std::cout << monthWeekday << " ";
    std::cout << month_weekday(February, Monday[3]) << '\n';
 
    constexpr auto monthWeekDayLast{June/Sunday[last]};
    std::cout << monthWeekDayLast << " ";
    std::cout << month_weekday_last(June, weekday_last(Sunday)) << '\n';

    std::cout << '\n';

}