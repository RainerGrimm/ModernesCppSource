// null.cpp

#include <iostream>
#include <typeinfo>

int main(){

  std::cout << std::endl;

  int a= 0;
  int* b= 0;
  auto c= 0;
  std::cout << typeid(c).name() << std::endl;

  auto res= a+b+c;
  std::cout << "res: " << res << std::endl;
  std::cout << typeid(res).name() << std::endl;
  
  std::cout << std::endl;

}