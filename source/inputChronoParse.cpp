// inputChronoParse.cpp

#include <chrono>
#include <iostream>
#include <string>
#include <sstream>

int main() {

    std::cout << '\n';

    std::chrono::sys_seconds timePoint;
    std::istringstream iStream1{"2021-08-11 21:49:35"};
    iStream1 >> std::chrono::parse("%F %T", timePoint);
    if (iStream1) std::cout << "timePoint: "  << timePoint << '\n';
    else std::cerr << "timepoint: Reading failed\n";

    std::chrono::year_month_day date1;
    std::istringstream iStream2{"11/08/21"};
    iStream2 >> std::chrono::parse("%x", date1);
    if (iStream2) std::cout << "date1: "  << date1 << '\n';
    else std::cerr << "date1: Reading failed\n";

    std::chrono::year_month_day date2;
    std::istringstream iStream3{"11/15/21"};
    iStream3 >> std::chrono::parse("%x", date2);
    if (iStream3) std::cout << "date2: "  << date2 << '\n';
    else std::cerr << "date2: Reading failed\n";

    std::cout << '\n';

}