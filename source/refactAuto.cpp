// refactAuto.cpp

#include <typeinfo>
#include <iostream>

int main(){
  
  std::cout << std::endl;

  auto a= 5;
  auto b= 10;
  auto sum=  a * b * 3;
  auto res= sum + 10; 
  std::cout << "typeid(res).name(): " << typeid(res).name() << std::endl;
  
  auto a2= 5;
  auto b2= 10.5;
  auto sum2= a2 * b2 * 3;
  auto res2= sum2 * 10;  
  std::cout << "typeid(res2).name(): " << typeid(res2).name() << std::endl;
  
  auto a3= 5;
  auto b3= 10;
  auto sum3= a3 * b3 * 3.1f;
  auto res3= sum3 * 10;  
  std::cout << "typeid(res3).name(): " << typeid(res3).name() << std::endl;
  
  std::cout << std::endl;
   
}