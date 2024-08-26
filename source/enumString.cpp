// enumString.cpp

#include <iostream>
#include <experimental/meta>
#include <string>
#include <type_traits>

// start 'expand' definition
namespace __impl {
  template<auto... vals>
  struct replicator_type {
    template<typename F>
      constexpr void operator>>(F body) const {
        (body.template operator()<vals>(), ...);
      }
  };

  template<auto... vals>
  replicator_type<vals...> replicator = {};
}

template<typename R>
consteval auto expand(R range) {
  std::vector<std::meta::info> args;
  for (auto r : range) {
    args.push_back(std::meta::reflect_value(r));
  }
  return substitute(^__impl::replicator, args);
}
// end 'expand' definition

template<typename E>
  requires std::is_enum_v<E>                      // (1)
constexpr std::string enum_to_string(E value) {
  std::string result = "<unnamed>";
  [:expand(std::meta::enumerators_of(^E)):] >>    // (2)
  [&]<auto e>{
    if (value == [:e:]) {
      result = std::meta::identifier_of(e);       // (3)
    }
  };
  return result;
}


int main() {

    std::cout << '\n';

    enum Color { red, green, blue };
    std::cout << "enum_to_string(Color::red): " << enum_to_string(Color::red) << '\n';
    // std::cout << "enum_to_string(42): " << enum_to_string(42) << '\n'; 

    std::cout << '\n';

}