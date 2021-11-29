// compare.cpp

#include <cstdint>
#include <iostream>
#include <type_traits>

class Base{};
class Derived: public Base{};

int main(){
  
  std::cout << std::boolalpha << '\n';
  
  std::cout << "std::is_base_of<Base,Derived>::value: " << std::is_base_of<Base,Derived>::value << '\n';
  std::cout << "std::is_base_of<Derived,Base>::value: " << std::is_base_of<Derived,Base>::value << '\n';
  std::cout << "std::is_base_of<Derived,Derived>::value: " << std::is_base_of<Derived,Derived>::value << '\n';
  
  // static_assert(std::is_base_of<Derived,Base>::value,"Derived is not base of Base");
  
  std::cout << '\n';
  
  std::cout << "std::is_convertible<Base*,Derived*>::value: " << std::is_convertible<Base*,Derived*>::value << '\n';
  std::cout << "std::is_convertible<Derived*,Base*>::value: " << std::is_convertible<Derived*,Base*>::value << '\n';
  std::cout << "std::is_convertible<Derived*,Derived*>::value: " << std::is_convertible<Derived*,Derived*>::value << '\n';
  
  // static_assert(std::is_convertible<Base*,Derived*>::value,"Base* can not be converted to Derived*");
  
  std::cout << '\n';
  
  std::cout << "std::is_same<int, int32_t>::value: " << std::is_same<int, int32_t>::value << '\n';
  std::cout << "std::is_same<int, int64_t>::value: " << std::is_same<int, int64_t>::value << '\n';
  std::cout << "std::is_same<long int, int64_t>::value: " << std::is_same<long int, int64_t>::value << '\n';
  
  // static_assert(std::is_same<int, int64_t>::value,"int is not the same type as int64_t");
  
  std::cout << '\n';
  
}