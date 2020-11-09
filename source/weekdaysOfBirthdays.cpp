// weekdaysOfBirthdays.cpp

#include <cstdlib>
#include <iostream>
#include "date.h"

int main() {

    std::cout << std::endl;

    using namespace date;

    int y;
    int m;
    int d;

    std::cout << "Year: ";
    std::cin >> y;
    std::cout << "Month: ";
    std::cin >> m;
    std::cout << "Day: ";
    std::cin >> d;

    std::cout << std::endl;

    auto birthday = year(y)/month(m)/day(d);

    if (not birthday.ok()) {
        std::cout << birthday << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::cout << "Birthday: " << birthday << std::endl;
    auto birthdayWeekday = year_month_weekday(birthday);
    std::cout << "Weekday of birthday: " << birthdayWeekday.weekday() << std::endl;

    auto currentDate = year_month_day(floor<days>(std::chrono::system_clock::now()));  
    auto currentYear = currentDate.year();
    
    auto age = (int)currentDate.year() - (int)birthday.year();
    std::cout << "Your age: " << age << std::endl;

    std::cout << std::endl;

    std::cout << "Weekdays for your next 10 birthdays" << std::endl;

    for (int i = 1, newYear = (int)currentYear; i <= 10;  ++i ) {
        std::cout << "  Age " <<  ++age << std::endl;
        auto newBirthday = year(++newYear)/month(m)/day(d);
        std::cout << "    Birthday: " << newBirthday << std::endl;
        std::cout << "    Weekday of birthday: " 
                  << year_month_weekday(newBirthday).weekday() << std::endl;
    }

    std::cout << std::endl;

}