// nullMacro.cpp

#include <iostream>
#include <typeinfo>

std::string overloadTest(int){
  return "int";
}

std::string overloadTest(long int){
  return "long int";
}


int main(){

  std::cout << std::endl;
  
  int a= NULL;
  int* b= NULL;
  auto c= NULL;
  std::cout << typeid(c).name() << std::endl;
  std::cout << typeid(NULL).name() << std::endl;
  
  
  std::cout << "overloadTest(NULL)= " << overloadTest(NULL) << std::endl;
  
  std::cout << std::endl;

}