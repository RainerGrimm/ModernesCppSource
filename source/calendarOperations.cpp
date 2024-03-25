// calendarOperations.cpp

#include <chrono>
#include <iostream>

int main() {

  std::cout << '\n';

  using std::chrono::Monday;
  using std::chrono::Saturday;

  using std::chrono::March;
  using std::chrono::June;
  using std::chrono::July;

  using std::chrono::days;
  using std::chrono::months;
  using std::chrono::years;

  using std::chrono::last;

  using namespace std::chrono_literals;

  std::cout << std::boolalpha;

  std::cout << "March: " << March << '\n';                                            
  std::cout << "March + months(3): " << March + months(3) << '\n';                      // (1)
  std::cout << "March - months(25): " << March - months(25) << '\n';                    // (5)  
  std::cout << "July - June: " <<  July - June << '\n';                                 // (6)
  std::cout << "June < July: " << (June < July) << '\n';                                // (7)

  std::cout << '\n';
 
  std::cout << "Saturday: " << Saturday << '\n';
  std::cout << "Saturday + days(3): " << Saturday + days(3) << '\n';                    // (2)
  std::cout << "Saturday - days(22): " << Saturday - days(22) << '\n';                  // (8)
  std::cout << "Saturday - Monday: " <<  Saturday - Monday << '\n';                     // (9)

  std::cout << '\n';

  std::cout << "2021y/March: " << 2021y/March << '\n';                                  // (3)
  std::cout << "2021y/March + years(3) - months(35): "                                  // (10)
            << 2021y/March + years(3) - months(35) << '\n';
  std::cout << "2022y/July - 2021y/June: " << 2022y/July - 2021y/June << '\n';         // (11)
  std::cout << "2021y/June > 2021y/July: " << (2021y/June > 2021y/July) << '\n';       // (12)

  std::cout << '\n';

  std::cout << "2021y/March/Saturday[last]: " << 2021y/March/Saturday[last] << '\n';   // (4)
  std::cout << "2021y/March/Saturday[last] + months(13) + years(3): " 
            << 2021y/March/Saturday[last] + months(13) + years(3) << '\n';
  std::cout << "2021y/July/Saturday[last] - months(1) == 2021y/June/Saturday[last]: "
            << (2021y/July/Saturday[last] - months(1) == 2021y/June/Saturday[last]) 
            << '\n';

  std::cout << '\n';

}