#include <chrono>
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std::chrono_literals;

template <typename ZonedTime>
auto getMinutes(const ZonedTime& zonedTime) {                               // (1)              
    return std::chrono::floor<std::chrono::minutes>(zonedTime.get_local_time());
}

void printStartEndTimes(const std::chrono::local_days& localDay,           // (2) 
                        const std::chrono::hours& h, 
                        const std::chrono::hours& durationClass,
                        const std::initializer_list<std::string>& timeZones ) {
    
    std::chrono::zoned_time startDate{std::chrono::current_zone(), localDay + h}; // (4)  
    std::chrono::zoned_time endDate{std::chrono::current_zone(), 
                                    localDay + h + durationClass};
    std::cout << std::format("Local time: [{}, {}]\n", getMinutes(startDate), getMinutes(endDate));
                                                                                
    auto longestStringSize = std::max(timeZones, [](const std::string& a,  // (5) 
                       const std::string& b) { return a.size() < b.size(); }).size();

    std::string formatTimeZones = "  {0:<{3}} [{1}, {2}]\n";              // (7) 
    for (auto timeZone: timeZones) {                                      // (6) 
        std::cout << std::vformat(formatTimeZones, std::make_format_args(timeZone, 
                                                            getMinutes(std::chrono::zoned_time(timeZone, startDate)),
                                                            getMinutes(std::chrono::zoned_time(timeZone, endDate)),
                                                            longestStringSize + 1));                             
    }
 }

int main() {

    using namespace std::string_literals;
    
    std::cout << '\n';

    constexpr auto classDay{std::chrono::year(2021)/2/1};
    constexpr auto durationClass = 4h;
    auto timeZones = {"America/Los_Angeles"s, "America/Denver"s, 
                      "America/New_York"s, "Europe/London"s, 
                      "Europe/Minsk"s, "Europe/Moscow"s, 
                      "Asia/Kolkata"s, "Asia/Novosibirsk"s, 
                      "Asia/Singapore"s, "Australia/Perth"s, 
                      "Australia/Sydney"s};

    for (auto startTime: {7h, 13h, 17h}) {                              // (3) 
        printStartEndTimes(std::chrono::local_days{classDay}, startTime, 
                           durationClass, timeZones);
        std::cout << '\n';
    }

    std::cout << '\n';

}