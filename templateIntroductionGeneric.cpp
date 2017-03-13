// templateIntroductionGeneric.cpp

#include <iostream>
#include <string>
#include <typeinfo>
#include <utility>


template<typename T>
concept bool Generic(){
  return true;
}

Generic{T}
Generic gcd(T a, T b){
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

Generic{T} 
class ConstrainedClass{
public:
  ConstrainedClass(){
    std::cout << typeid(decltype(std::declval<T>())).name() << std::endl;
  }
};


int main(){
  
  std::cout << std::endl;
  
  std::cout << "gcd(100, 10): " << gcd(100, 10) << std::endl;
  
  std::cout << std::endl;
 
  ConstrainedClass<int> genericClassInt;
  ConstrainedClass<std::string> genericClassString;
  ConstrainedClass<double> genericClassDouble;
  
  std::cout << std::endl;

}
