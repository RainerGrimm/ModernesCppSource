// cuteSyntax.cpp

#include <iostream>
#include "date.h"

int main() {

    std::cout << std::endl;

    using namespace date;

    constexpr auto yearMonthDay{year(1966)/6/26};
    std::cout << yearMonthDay << std::endl;

    constexpr auto dayMonthYear{day(26)/6/1966};
    std::cout << dayMonthYear << std::endl;

    constexpr auto monthDayYear{month(6)/26/1966};
    std::cout << monthDayYear << std::endl;

    constexpr auto yearDayMonth{year(1966)/26/6};
    std::cout << yearDayMonth << std::endl;

    std::cout << std::endl;

}