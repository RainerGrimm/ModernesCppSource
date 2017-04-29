// inPlace.cpp

#include <optional>
#include <iostream>
#include <string>

int main(){
  
  std::cout << std::endl;
  
  // C string literal
  std::optional<std::string> opt1(std::in_place, "C++17");                        // 1

  // 5 characters 'C'
  std::optional<std::string> opt2(std::in_place,5, 'C');                          // 2

  // initializer list
  std::optional<std::string> opt3(std::in_place, {'C', '+', '+', '1', '7'});      // 3

  // Copy constructor
  std::optional<std::string> opt4(opt3);                                          // 4

  std::cout << *opt1 << std::endl;
  std::cout << *opt2 << std::endl;
  std::cout << *opt3 << std::endl;
  std::cout << *opt4 << std::endl;
  
  std::cout << std::endl;
    
}
