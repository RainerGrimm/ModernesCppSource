// reflectionClass.cpp

#include <experimental/meta>
#include <iostream>

struct Base { 
    int i{}; 
    void inc(int& j){ j++; }
};

consteval auto number(int n) {
  //return std::meta::nonstatic_data_members_of(^Base)[n];
  return std::meta::members_of(^Base)[n];
}


consteval auto named(std::string_view name) {
  for (std::meta::info field : std::meta::members_of(^Base)) {
    if (std::meta::has_identifier(field) && std::meta::identifier_of(field) == name)
      return field;
  } 
  return std::meta::info{};
}


int main() { 

  std::cout << '\n';

  Base base;
  base.[:number(0):] = 1;  
  // base.[:member_number(10):] = 1;  Error
  std::cout << "base.i= " << base.i << '\n';
  base.[:number(1):](base.i);
  std::cout << "base.i= " << base.i << '\n';

  std::cout << '\n';
 
  base.[:named("i"):] = 3;
  std::cout << "base.i= " << base.i << '\n';
  base.[:named("inc"):](base.i);
  std::cout << "base.i= " << base.i << '\n';

}
