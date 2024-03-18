// dayDays.cpp

#include <iostream>
#include <chrono>

int main() {

    std::cout << '\n';

    using namespace std::chrono_literals; 

    std::chrono::days days1 = std::chrono::day(30) - std::chrono::day(25);          
    std::chrono::days days2 = 30d - 25d;                                            
    if ( days1 == days2 && 
         days1 == std::chrono::days(5)) std::cout << "Five days\n";

    std::chrono::years years1 = std::chrono::year(2021) - std::chrono::year(1998);  
    std::chrono::years years2= 2021y - 1998y;                                       
    if ( years1 == years2 && 
         years1 == std::chrono::years(23)) std::cout << "Twenty-three years\n";

    std::cout << '\n';

}