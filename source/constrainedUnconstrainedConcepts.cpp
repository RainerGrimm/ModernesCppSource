// constrainedUnconstrainedConcepts.cpp

#include <iostream>
#include <type_traits>
#include <vector>

template<typename T>                                 // (1)
concept bool Integral(){                
  return std::is_integral<T>::value;
}

int getIntegral(int val){
  return val * 5;
}

int main(){
  
  std::cout << std::boolalpha << std::endl;
  
  std::vector<int> myVec{1, 2, 3, 4, 5};
  for (Integral& i: myVec) std::cout << i << " ";   // (2)
  std::cout << std::endl;  

  Integral b= true;                                 // (3)
  std::cout << b << std::endl;
  
  Integral integ= getIntegral(10);                  // (4)
  std::cout << integ << std::endl;
  
  auto integ1= getIntegral(10);                     // (5)
  std::cout << integ1 << std::endl;
  
  std::cout << std::endl;

}