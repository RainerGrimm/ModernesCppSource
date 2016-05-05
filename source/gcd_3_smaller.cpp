// gcd_3_smaller.cpp

#include <iostream>
#include <type_traits>
#include <typeinfo>

template<typename T1, typename T2>
typename std::conditional <(sizeof(T1) < sizeof(T2)), T1, T2>::type gcd(T1 a, T2 b){
  static_assert(std::is_integral<T1>::value, "T1 should be an integral type!");
  static_assert(std::is_integral<T2>::value, "T2 should be an integral type!");
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

int main(){

  std::cout << std::endl;

  std::cout << "gcd(100,10)= " <<  gcd(100,10)  << std::endl;
  std::cout << "gcd(100,33)= " << gcd(100,33) << std::endl;
  std::cout << "gcd(100,0)= " << gcd(100,0)  << std::endl;

  std::cout << std::endl;

  std::cout << "gcd(100,10LL)= " << gcd(100,10LL) << std::endl;

  std::conditional <(sizeof(100) < sizeof(10LL)), long long, long>::type uglyRes= gcd(100,10LL);
  auto res= gcd(100,10LL);
  auto res2= gcd(100LL,10L);

  std::cout << "typeid(gcd(100,10LL)).name(): " << typeid(res).name() << std::endl;
  std::cout << "typeid(gcd(100LL,10L)).name(): " << typeid(res2).name() << std::endl;

  std::cout << std::endl;

}
