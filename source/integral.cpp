// integral.cpp

#include <iostream>
#include <type_traits>

namespace rgr{

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

  template <class T>
  struct is_integral : public false_type{};

  template <>
  struct is_integral<bool> : public true_type{};

  template <>
  struct is_integral<char> : public true_type{};

  template <>
  struct is_integral<signed char> : public true_type{};

  template <>
  struct is_integral<unsigned char> : public true_type{};

  template <>
  struct is_integral<wchar_t> : public true_type{};

  template <>
  struct is_integral<short> : public true_type{};

  template <>
  struct is_integral<int> : public true_type{};

  template <>
  struct is_integral<long> : public true_type{};

  template <>
  struct is_integral<long long> : public true_type{};

  template <>
  struct is_integral<unsigned short> : public true_type{};

  template <>
  struct is_integral<unsigned int> : public true_type{};

  template <>
  struct is_integral<unsigned long> : public true_type{};

  template <>
  struct is_integral<unsigned long long> : public true_type{};
  
}

int main(){
  
  std::cout << std::boolalpha << std::endl;
  
  std::cout << "std::is_integral<int>::value: " << std::is_integral<int>::value << std::endl;
  std::cout << "rgr::is_integral<int>::value: " << rgr::is_integral<int>::value << std::endl;
  
  std::cout << "std::is_integral<double>::value: " << std::is_integral<double>::value << std::endl;
  std::cout << "rgr::is_integral<double>::value: " << rgr::is_integral<double>::value << std::endl;
  
  std::cout << std::endl;
  
  std::cout << "std::true_type::value: " << std::true_type::value << std::endl;
  std::cout << "rgr::true_type::value: " << rgr::true_type::value << std::endl;
  
  std::cout << "std::false_type::value: " << std::false_type::value << std::endl;
  std::cout << "rgr::false_type::value: " << rgr::false_type::value << std::endl;
  
  std::cout << std::endl;
  
  std::cout << "std::integral_constant<bool, true>::value: " << std::integral_constant<bool, true>::value << std::endl;
  std::cout << "rgr::integral_constant<bool, true>::value: " << rgr::integral_constant<bool, true>::value << std::endl;
  
  std::cout << "std::integral_constant<bool, false>::value: " << std::integral_constant<bool, false>::value << std::endl;
  std::cout << "rgr::integral_constant<bool, false>::value: " << rgr::integral_constant<bool, false>::value << std::endl;  
  
  std::cout << std::endl;
  
}