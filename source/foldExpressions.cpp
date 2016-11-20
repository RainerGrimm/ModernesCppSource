// foldExpression.cpp

#include <iostream>

bool allVar(){
  return true;
}

template<typename T, typename ...Ts>
bool allVar(T t, Ts ... ts){
  return t && allVar(ts...);
}

template<typename... Args>
bool all(Args... args) { return (... && args); }

int main(){

  std::cout << std::boolalpha;

  std::cout << "allVar(): " << allVar() << std::endl;
  std::cout << "all(): " << all() << std::endl;

  std::cout << "allVar(true): " << allVar(true) << std::endl;
  std::cout << "all(true): " << all(true) << std::endl;

  std::cout << "allVar(true, true, true, false): " << allVar(true, true, true, false) << std::endl;
  std::cout << "all(true, true, true, false): " << all(true, true, true, false) << std::endl;

}