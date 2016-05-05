// compare.cpp

#include <cstdint>
#include <iostream>
#include <type_traits>

class Base{};
class Derived: public Base{};

int main(){
  
  std::cout << std::boolalpha << std::endl;
  
  std::cout << "std::is_base_of<Base,Derived>::value: " << std::is_base_of<Base,Derived>::value << std::endl;
  std::cout << "std::is_base_of<Derived,Base>::value: " << std::is_base_of<Derived,Base>::value << std::endl;
  std::cout << "std::is_base_of<Derived,Derived>::value: " << std::is_base_of<Derived,Derived>::value << std::endl;
  
  // static_assert(std::is_base_of<Derived,Base>::value,"Derived is not base of Base");
  
  std::cout << std::endl;
  
  std::cout << "std::is_convertible<Base*,Derived*>::value: " << std::is_convertible<Base*,Derived*>::value << std::endl;
  std::cout << "std::is_convertible<Derived*,Base*>::value: " << std::is_convertible<Derived*,Base*>::value << std::endl;
  std::cout << "std::is_convertible<Derived*,Derived*>::value: " << std::is_convertible<Derived*,Derived*>::value << std::endl;
  
  // static_assert(std::is_convertible<Base*,Derived*>::value,"Base* can not be converted to Derived*");
  
  std::cout << std::endl;
  
  std::cout << "std::is_same<int, int32_t>::value: " << std::is_same<int, int32_t>::value << std::endl;
  std::cout << "std::is_same<int, int64_t>::value: " << std::is_same<int, int64_t>::value << std::endl;
  std::cout << "std::is_same<long int, int64_t>::value: " << std::is_same<long int, int64_t>::value << std::endl;
  
  // static_assert(std::is_same<int, int64_t>::value,"int is not the same type as int64_t");
  
  std::cout << std::endl;
  
}