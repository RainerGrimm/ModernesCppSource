//  leapYear.cpp

#include <chrono>
#include <iostream>
 
int main() {

    std::cout << std::boolalpha << '\n';

    std::cout << "Valid days" << '\n';                         // (1)
    std::chrono::day day31(31);
    std::chrono::day day32 = day31 + std::chrono::days(1);
    std::cout << "  day31: " << day31 << "; ";
    std::cout << "day31.ok(): "  << day31.ok() << '\n';
    std::cout << "  day32: " << day32 << "; ";
    std::cout << "day32.ok(): "  << day32.ok() << '\n';
   

    std::cout << '\n';

    std::cout << "Valid months" << '\n';                      // (2)
    std::chrono::month month1(1);
    std::chrono::month month0(0);
    std::cout << "  month1: " << month1 << "; ";
    std::cout << "month1.ok(): "  << month1.ok() << '\n';
    std::cout << "  month0: " << month0 << "; ";
    std::cout << "month0.ok(): "  << month0.ok() << '\n';

    std::cout << '\n';

    std::cout << "Valid years" << '\n';                       // (3)
    std::chrono::year year2020(2020);
    std::chrono::year year32768(-32768);
    std::cout << "  year2020: " << year2020 << "; ";
    std::cout << "year2020.ok(): "  << year2020.ok() << '\n';
    std::cout << "  year32768: " << year32768 << "; ";
    std::cout << "year32768.ok(): "  << year32768.ok() << '\n';

    std::cout << '\n';

    std::cout << "Leap Years"  << '\n';       

    constexpr auto leapYear2016{std::chrono::year(2016)/2/29};
    constexpr auto leapYear2020{std::chrono::year(2020)/2/29};
    constexpr auto leapYear2024{std::chrono::year(2024)/2/29};

    std::cout << "  leapYear2016.ok(): " << leapYear2016.ok() << '\n';
    std::cout << "  leapYear2020.ok(): " << leapYear2020.ok() << '\n';
    std::cout << "  leapYear2024.ok(): " << leapYear2024.ok() << '\n';

    std::cout << '\n';

     std::cout << "No Leap Years"  << '\n';   

    constexpr auto leapYear2100{std::chrono::year(2100)/2/29};
    constexpr auto leapYear2200{std::chrono::year(2200)/2/29};
    constexpr auto leapYear2300{std::chrono::year(2300)/2/29};

    std::cout << "  leapYear2100.ok(): " << leapYear2100.ok() << '\n';
    std::cout << "  leapYear2200.ok(): " << leapYear2200.ok() << '\n';
    std::cout << "  leapYear2300.ok(): " << leapYear2300.ok() << '\n';

    std::cout << '\n';

    std::cout << "Leap Years"  << '\n';      

    constexpr auto leapYear2000{std::chrono::year(2000)/2/29};
    constexpr auto leapYear2400{std::chrono::year(2400)/2/29};
    constexpr auto leapYear2800{std::chrono::year(2800)/2/29};

    std::cout << "  leapYear2000.ok(): " << leapYear2000.ok() << '\n';
    std::cout << "  leapYear2400.ok(): " << leapYear2400.ok() << '\n';
    std::cout << "  leapYear2800.ok(): " << leapYear2800.ok() << '\n';

    std::cout << '\n';

}
