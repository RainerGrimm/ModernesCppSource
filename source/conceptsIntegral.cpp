// conceptsIntegral.cpp

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

int main(){

  std::cout << std::endl;

  std::cout << "gcd(100, 10)= " <<  gcd(100, 10)  << std::endl;
  std::cout << "gcd(100, 33)= " << gcd(100, 33) << std::endl;
  // std::cout << "gcd(5.5, 4,5)= " << gcd(5.5, 4.5) << std::endl;

  std::cout << std::endl;

}

