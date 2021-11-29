// isSameIgnoringConstVolatile.cpp

#include <iostream>
#include <type_traits>

namespace rgr {

  template<class T, T v>
  struct integral_constant {
      static constexpr T value = v;
      typedef T value_type;
      typedef integral_constant type;
      constexpr operator value_type() const noexcept { return value; }
      constexpr value_type operator()() const noexcept { return value; } //since c++14
  };

  typedef integral_constant<bool, true> true_type;                       
  typedef integral_constant<bool, false> false_type;
  
  template<typename T, typename U>
  struct isSameIgnoringConstVolatile: std::integral_constant<
         bool,
         rgr::is_same<typename std::remove_cv<T>::type, 
                      typename std::remove_cv<U>::type>::value  
     > {};

}

int main() {

    std::cout << '\n';

    std::cout << std::boolalpha;

    std::cout << "rgr::isSameIgnoringConstVolatile<int, const int>::value: " 
              << rgr::isSameIgnoringConstVolatile<int, const int>::value << '\n';
    std::cout << "rgr::is_same<int, volatile int>::value: " 
              << rgr::isSameIgnoringConstVolatile<int, volatile int>::value << '\n';
    std::cout << "rgr::isSameIgnoringConstVolatile<int, int>::value: "  
              << rgr::isSameIgnoringConstVolatile<int, int>::value << '\n';

    std::cout << '\n';

}