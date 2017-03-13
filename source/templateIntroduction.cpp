// templateIntroduction.cpp

#include <type_traits>
#include <iostream>

template<typename T>
concept bool Integral(){
  return std::is_integral<T>::value;
}

Integral{T}
Integral gcd(T a, T b){
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

Integral{T} 
class ConstrainedClass{};

/*

auto{T}
T gcd(T a, T b){
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

auto{T} 
class ConstrainedClass{};

*/


int main(){
  
  std::cout << std::endl;
  
  auto res= gcd(100, 10); 

  ConstrainedClass<int> constrainedClass;
  ConstrainedClass<double> constrainedClass1;
  
  std::cout << std::endl;

}
