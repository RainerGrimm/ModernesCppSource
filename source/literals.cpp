// literals.cpp

#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

int main(){

  std::cout << std::endl;

  auto schoolHour= 45min;

  auto shortBreak= 300s;
  auto longBreak= 0.25h;

  auto schoolWay= 15min;
  auto homework= 2h;

  auto schoolDayInSeconds= 2*schoolWay + 6 * schoolHour + 4 * shortBreak + longBreak + homework;
  
  std::cout << "School day in seconds: " << schoolDayInSeconds.count() << std::endl;
  
  std::cout << "School day in minutes: " << schoolDayInSeconds.count() / 60 << std::endl;
  
  std::cout << "School day in hours: " << schoolDayInSeconds.count() / 3600 << std::endl;

  std::cout << std::endl;

}