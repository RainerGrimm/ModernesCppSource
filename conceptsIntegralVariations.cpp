// conceptsIntegralVariations.cpp

#include <type_traits>
#include <iostream>

template<typename T>
concept bool Integral(){
  return std::is_integral<T>::value;
}

template<typename T>
requires Integral<T>()
T gcd(T a, T b){
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

template<Integral T>
T gcd1(T a, T b){
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

Integral gcd2(Integral a, Integral b){
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

auto gcd3(auto a, auto b){
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

int main(){

  std::cout << std::endl;

  std::cout << "gcd(100, 10)= "  <<  gcd(100, 10)  << std::endl;
  std::cout << "gcd1(100, 10)= " <<  gcd1(100, 10)  << std::endl;
  std::cout << "gcd2(100, 10)= " <<  gcd2(100, 10)  << std::endl;
  std::cout << "gcd3(100, 10)= " <<  gcd3(100, 10)  << std::endl;

  std::cout << std::endl;

}
