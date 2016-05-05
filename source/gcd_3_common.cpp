// gcd_3_common.cpp

#include <iostream>
#include <type_traits>
#include <typeinfo>

template<typename T1, typename T2>
typename std::common_type<T1, T2>::type gcd(T1 a, T2 b){
  static_assert(std::is_integral<T1>::value, "T1 should be an integral type!");
  static_assert(std::is_integral<T2>::value, "T2 should be an integral type!");
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

int main(){

  std::cout << std::endl;

  std::cout << "typeid(gcd(100,10)).name(): " << typeid(gcd(100,10)).name() << std::endl;
  std::cout << "typeid(gcd(100,10L)).name(): " << typeid(gcd(100,10L)).name() << std::endl;
  std::cout << "typeid(gcd(100,10LL)).name(): " << typeid(gcd(100,10LL)).name() << std::endl;

  std::cout << std::endl;

}
