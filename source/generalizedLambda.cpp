// generalizedLambda

#include <iostream>
#include <string>
#include <typeinfo>

int main(){
    
  std::cout << std::endl;
  
  auto myAdd= [](auto fir, auto sec){ return fir+sec; };
  
  std::cout << "myAdd(1, 10)= " << myAdd(1, 10) << std::endl;
  std::cout << "myAdd(1, 10.0)= " << myAdd(1, 10.0) << std::endl;
  std::cout << "myAdd(std::string(1),std::string(10.0)= " 
            <<  myAdd(std::string("1"),std::string("10")) << std::endl;
  std::cout << "myAdd(true, 10.0)= " << myAdd(true, 10.0) << std::endl;
  
  std::cout << std::endl;
  
  std::cout << "typeid(myAdd(1, 10)).name()= " << typeid(myAdd(1, 10)).name() << std::endl;
  std::cout << "typeid(myAdd(1, 10.0)).name()= " << typeid(myAdd(1, 10.0)).name() << std::endl;
  std::cout << "typeid(myAdd(std::string(1), std::string(10))).name()= " 
            << typeid(myAdd(std::string("1"), std::string("10"))).name() << std::endl;
  std::cout << "typeid(myAdd(true, 10.0)).name()= " << typeid(myAdd(true, 10.0)).name() << std::endl;
    
  std::cout << std::endl;

}