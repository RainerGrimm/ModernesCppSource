// convertClocks.cpp

#include <iostream>
#include <sstream>
#include <chrono>

int main() {

  std::cout << '\n';

  using namespace std::literals;

  std::chrono::utc_time<std::chrono::utc_clock::duration> timePoint;
  std::istringstream{"2021-8-5 17:00:00"} >> std::chrono::parse("%F %T"s, timePoint);

  auto timePointUTC = std::chrono::clock_cast<std::chrono::utc_clock>(timePoint);
  std::cout << "UTC_time:  " << std::format("{:%F %X %Z}", timePointUTC) << '\n';

  auto timePointSys = std::chrono::clock_cast<std::chrono::system_clock>(timePoint);
  std::cout << "sys_time:  " << std::format("{:%F %X %Z}", timePointSys) << '\n';

  auto timePointFile = std::chrono::clock_cast<std::chrono::file_clock>(timePoint);
  std::cout << "file_time: " << std::format("{:%F %X %Z}", timePointFile) << '\n';

  auto timePointGPS = std::chrono::clock_cast<std::chrono::gps_clock>(timePoint);
  std::cout << "GPS_time:  " << std::format("{:%F %X %Z}", timePointGPS) << '\n';

  auto timePointTAI = std::chrono::clock_cast<std::chrono::tai_clock>(timePoint);
  std::cout << "TAI_time:  " << std::format("{:%F %X %Z}", timePointTAI) << '\n';

  std::cout << '\n';

}