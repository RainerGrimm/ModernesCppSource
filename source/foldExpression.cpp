// foldExpression.cpp

#include <iostream>

template<typename... Args>
bool all(Args... args) { return (... && args); }

template<typename... Args>
bool any(Args... args) { return (... || args); }

template<typename... Args>
bool none(Args... args) { return not(... || args); }


int main(){
    
  std::cout << std::endl;

  std::cout << std::boolalpha;

  std::cout << "all(true): " << all(true) << std::endl;
  std::cout << "any(true): " << any(true) << std::endl;
  std::cout << "none(true): " << none(true) << std::endl;
  
  std::cout << std::endl;

  std::cout << "all(true, true, true, false): " << all(true, true, true, false) << std::endl;
  std::cout << "any(true, true, true, false): " << any(true, true, true, false) << std::endl;
  std::cout << "none(true, true, true, false): " << none(true, true, true, false) << std::endl;
  
  std::cout << std::endl;
  
  std::cout << "all(fasle, false, false, false): " << all(false, false, false, false) << std::endl;
  std::cout << "any(fasle, false, false, false): " << any(false, false, false, false) << std::endl;
  std::cout << "none(fasle, false, false, false): " << none(false, false, false, false) << std::endl;
  
  std::cout << std::endl;
  
}