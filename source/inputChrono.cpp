// inputChrono.cpp

#include <chrono>
#include <iostream>
#include <string>
#include <sstream>

int main() {

    std::cout << '\n';

    std::chrono::sys_seconds timePoint;
    std::istringstream iStream1{"2021-08-11 21:49:35"};              //(1)
    std::chrono::from_stream(iStream1, "%F %T", timePoint);          //(2)
    if (iStream1) std::cout << "timePoint: "  << timePoint << '\n';
    else std::cerr << "timepoint: Reading failed\n";

    std::chrono::year_month_day date1;
    std::istringstream iStream2{"11/08/21"};                         //(3)
    std::chrono::from_stream(iStream2, "%x", date1);                 //(4)
    if (iStream2) std::cout << "date1: "  << date1 << '\n';
    else std::cerr << "date1: Reading failed\n";

    std::chrono::year_month_day date2;
    std::istringstream iStream3{"11/15/21"};
    std::chrono::from_stream(iStream3, "%x", date2);                  //(5)
    if (iStream3) std::cout << "date2: "  << date2 << '\n';
    else std::cerr << "date2: Reading failed\n";

    std::cout << '\n';

}