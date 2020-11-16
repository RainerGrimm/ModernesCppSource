// ordinalDate.cpp

#include "date.h"
#include <iomanip>
#include <iostream>

int main()
{
   using namespace date;
   
   const auto time = std::chrono::system_clock::now();
   const auto daypoint = floor<days>(time);
   const auto ymd = year_month_day{daypoint};
   
   // calculating the year and the day of the year
   const auto year = ymd.year();
   const auto year_day = daypoint - sys_days{year/January/0};
   
   std::cout << year << '-' << std::setfill('0') << std::setw(3) << year_day.count() << std::endl;
   
   // inverse calculation and check
   assert(ymd == year_month_day{sys_days{year/January/0} + year_day});
}