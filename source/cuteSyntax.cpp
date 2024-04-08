// cuteSyntax.cpp

#include <chrono>
#include <iostream>

int main() {

    std::cout << '\n';

    constexpr auto yearMonthDay{std::chrono::year(1966)/6/26};
    std::cout << yearMonthDay << '\n';

    constexpr auto dayMonthYear{std::chrono::day(26)/6/1966};
    std::cout << dayMonthYear << '\n';

    constexpr auto monthDayYear{std::chrono::month(6)/26/1966};
    std::cout << monthDayYear << '\n';

    constexpr auto yearDayMonth{std::chrono::year(1966)/std::chrono::month(26)/6};  
    std::cout << yearDayMonth << '\n';

    std::cout << '\n';

}