// weekdaysOfBirthdays.cpp

#include <chrono>
#include <cstdlib>
#include <iostream>

int main() {

    std::cout << '\n';

    int y;
    int m;
    int d;

    std::cout << "Year: ";                                            // (1)                          
    std::cin >> y;
    std::cout << "Month: ";
    std::cin >> m;
    std::cout << "Day: ";
    std::cin >> d;

    std::cout << '\n';

    auto birthday = std::chrono::year(y)/std::chrono::month(m)/std::chrono::day(d);  // (2)      

    if (not birthday.ok()) {                                         // (3)                     
        std::cout << birthday << '\n';
        std::exit(EXIT_FAILURE);
    }

    std::cout << "Birthday: " << birthday << '\n';
    auto birthdayWeekday = std::chrono::year_month_weekday(birthday); // (4)  
    std::cout << "Weekday of birthday: " << birthdayWeekday.weekday() << '\n';

    auto currentDate = std::chrono::year_month_day(
        std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()));  
    auto currentYear = currentDate.year();
    
    auto age = static_cast<int>(currentDate.year()) - 
               static_cast<int>(birthday.year());                     // (5)
    std::cout << "Your age: " << age << '\n';

    std::cout << '\n';

    std::cout << "Weekdays for your next 10 birthdays" << '\n';  

    for (int i = 1, newYear = (int)currentYear; i <= 10;  ++i ) {    // (6)
        std::cout << "  Age " <<  ++age << '\n';
        auto newBirthday = std::chrono::year(++newYear)/
                           std::chrono::month(m)/std::chrono::day(d);
        std::cout << "    Birthday: " << newBirthday << '\n';
        std::cout << "    Weekday of birthday: " 
                  << std::chrono::year_month_weekday(newBirthday).weekday() << '\n';
    }

    std::cout << '\n';

}