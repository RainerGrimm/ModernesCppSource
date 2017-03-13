// conceptsPlaceholder.cpp

#include <iostream>
#include <type_traits>
#include <vector>

template<typename T>
concept bool Integral(){
  return std::is_integral<T>::value;
}

Integral getIntegral(auto val){
  return val;
}

int main(){
  
  std::cout << std::boolalpha << std::endl;
  
  std::vector<int> myVec{1, 2, 3, 4, 5};
  for (Integral& i: myVec) std::cout << i << " ";
  std::cout << std::endl;  

  Integral b= true;
  std::cout << b << std::endl;
  
  Integral integ= getIntegral(10);
  std::cout << integ << std::endl;
  
  auto integ1= getIntegral(10);
  std::cout << integ1 << std::endl;
  
  std::cout << std::endl;

}
