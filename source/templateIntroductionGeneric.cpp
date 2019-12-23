// templateIntroductionGeneric.cpp

#include <iostream>
#include <string>
#include <typeinfo>
#include <utility>

struct NoDefaultConstructor{               // (5)
    NoDefaultConstructor() = delete;
};

template<typename T>                       // (1)
concept bool Generic(){
  return true;
}

Generic{T}                                 // (2)
Generic gcd(T a, T b){
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

Generic{T}                                 // (3)
class ConstrainedClass{
public:
  ConstrainedClass(){
    std::cout << typeid(decltype(std::declval<T>())).name()   // (4)
              << std::endl;
  }
};


int main(){
  
  std::cout << std::endl;
  
  std::cout << "gcd(100, 10): " << gcd(100, 10) << std::endl;
  
  std::cout << std::endl;
 
  ConstrainedClass<int> genericClassInt;
  ConstrainedClass<std::string> genericClassString;
  ConstrainedClass<double> genericClassDouble;
  ConstrainedClass<NoDefaultConstructor> genericNoDefaultConstructor;
  
  std::cout << std::endl;

}
