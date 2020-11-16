// onlineClass.cpp

#include "date/tz.h"
#include <algorithm>
#include <iomanip>
#include <iostream>

template <typename ZonedTime>
auto getMinutes(const ZonedTime& zonedTime) {
    return date::floor<std::chrono::minutes>(zonedTime.get_local_time());
}

void printStartEndTimes(const date::local_days& localDay, 
                        const std::chrono::hours& h, 
                        const std::chrono::hours& durationClass,
                        const std::initializer_list<std::string>& timeZones ){

    int longestStringSize = std::max(timeZones, [](const std::string& a, const std::string& b) { return a.size() < b.size(); }).size();
    
    date::zoned_time startDate{date::current_zone(), localDay + h};
    date::zoned_time endDate{date::current_zone(), localDay + h + durationClass};

    std::cout << "Local time: ["  << getMinutes(startDate) << ", " 
                                  << getMinutes(endDate) << "]" << std::endl;
    for (auto timeZone: timeZones) {
        std::cout << "  " << std::setw(longestStringSize + 1) << std::left 
                  << timeZone 
                  << "[" << getMinutes(date::zoned_time(timeZone, startDate))
                  << ", " << getMinutes(date::zoned_time(timeZone, endDate)) 
                  << "]" << std::endl;

    }
 }

int main() {

    using namespace std::string_literals;
    using namespace std::chrono;
    
    std::cout << std::endl;

    constexpr auto classDay{date::year(2021)/2/1};
    constexpr auto durationClass = 4h;
    auto timeZones = {"America/Los_Angeles"s, "America/Denver"s, "America/New_York"s, 
                      "Europe/London"s, "Europe/Minsk"s, "Europe/Moscow"s, 
                      "Asia/Kolkata"s, "Asia/Novosibirsk"s, "Asia/Singapore"s,
                      "Australia/Perth"s, "Australia/Sydney"s};

    for (auto startTime: {7h, 13h, 17h}) {
        printStartEndTimes(date::local_days{classDay}, startTime, 
                           durationClass, timeZones);
        std::cout << std::endl;
    }

}