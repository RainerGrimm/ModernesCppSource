// foldExpressionAll.cpp

#include <iostream>

template<typename... Args>
bool all(Args... args) { return (... && args); }

int main(){

  std::cout << std::boolalpha;

  std::cout << "all(): " << all() << std::endl;
  std::cout << "all(true): " << all(true) << std::endl;
  std::cout << "all(true, true, true, false): " << all(true, true, true, false) << std::endl;

  std::cout << std::endl;

}
