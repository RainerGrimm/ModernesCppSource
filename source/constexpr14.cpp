// consexpr14.cpp

#include <iostream>

constexpr auto gcd(int a, int b){
  while (b != 0){
    auto t= b;
    b= a % b;
    a= t;
  }
  return a;
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
