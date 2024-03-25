// timeOfDay.cpp

#include "date.h"
#include <iostream>

int main() {
                                                            
     using namespace std::chrono_literals; 

     std::cout << std::boolalpha << std::endl;
    
     auto timeOfDay = date::hh_mm_ss(10.5h + 98min + 2020s + 0.5s);                    // (1)
    
     std::cout<< "timeOfDay: " << timeOfDay << std::endl;                              // (2)

     std::cout << std::endl;

     std::cout << "timeOfDay.hours(): " << timeOfDay.hours() << std::endl;             // (4)
     std::cout << "timeOfDay.minutes(): " << timeOfDay.minutes() << std::endl;         // (4)
     std::cout << "timeOfDay.seconds(): " << timeOfDay.seconds() << std::endl;         // (4)
     std::cout << "timeOfDay.subseconds(): " << timeOfDay.subseconds() << std::endl;   // (4)
     std::cout << "timeOfDay.to_duration(): " << timeOfDay.to_duration() << std::endl; // (5)

     std::cout << std::endl;

     std::cout << "date::hh_mm_ss(45700.5s): " << date::hh_mm_ss(45700.5s) << '\n';  // (6)

     std::cout << std::endl;

     std::cout << "date::is_am(5h): " << date::is_am(5h) << std::endl;                 // (7)    
     std::cout << "date::is_am(15h): " << date::is_am(15h) << std::endl;               // (7)

     std::cout << std::endl;
     
     std::cout << "date::make12(5h): " << date::make12(5h) << std::endl;               // (7)   
     std::cout << "date::make12(15h): " << date::make12(15h) << std::endl;             // (7) 

}