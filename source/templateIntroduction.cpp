// templateIntroduction.cpp

#include <type_traits>
#include <iostream>

template<typename T>
concept bool Integral(){
  return std::is_integral<T>::value;
}

Integral{T}                            // (1)
Integral gcd(T a, T b){
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

Integral{T}                            // (2)
class ConstrainedClass{};

/*

auto{T}                                // (3)
auto gcd(T a, T b){
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

auto{T}                                // (4)
class ConstrainedClass{};

*/


int main(){
  
  std::cout << std::endl;
  
  auto res= gcd(100, 10); 

  ConstrainedClass<int> constrainedClass;
  ConstrainedClass<double> constrainedClass1;
  
  std::cout << std::endl;

}
