// daveed.cpp

#include <array>
#include <experimental/meta>
#include <iostream>

template<typename E> 
struct enum_item { 
  std::string_view name; 
  E value;
};

template<typename E> 
consteval auto get_enum_data() {
  std::array<enum_item<E>, std::meta::enumerators_of(^E).size()> result;
  int k = 0;
  for (auto mem: std::meta::enumerators_of(^E))
    result[k++] = enum_item<E>{ std::meta::identifier_of(mem), std::meta::extract<E>(mem) };
  return result;
}

enum MyEnum { 
  x, 
  y, 
  e = -1, 
  z = 99 
};

int main() {

  std::cout << '\n';

  std::cout << "members of " << std::meta::identifier_of(^MyEnum) << '\n';
  for (auto x: get_enum_data<MyEnum>()) {
    std::cout << "  " << x.name << " = " << (long)x.value << '\n';
  }

  std::cout << '\n';

}