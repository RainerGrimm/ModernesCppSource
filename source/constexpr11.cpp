// constexpr11.cpp

#include <iostream>

constexpr int gcd(int a, int b){
  return (b== 0) ? a : gcd(b, a % b);
}

int main(){
  
  std::cout << std::endl;
  
  constexpr int i= gcd(11,121);
  
  int a= 11;
  int b= 121;
  int j= gcd(a,b);

  std::cout << "gcd(11,121): " << i << std::endl;
  std::cout << "gcd(a,b): " << j << std::endl;
  
  std::cout << std::endl;
 
}
