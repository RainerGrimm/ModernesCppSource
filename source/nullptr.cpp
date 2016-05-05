// nullptr.cpp

#include <iostream>
#include <string>

std::string overloadTest(char*){
  return "char*";
}

std::string overloadTest(long int){
  return "long int";
}

int main(){

  std::cout << std::endl;

  long int* pi = nullptr;       
  // long int i= nullptr;       // ERROR
  auto nullp= nullptr;          // type std::nullptr_t
  
  bool b = nullptr;           
  std::cout << std::boolalpha << "b: "  << b << std::endl;
  auto val= 5;
  if ( nullptr < &val ){ std::cout << "nullptr < &val" << std::endl; }  

  // calls char*
  std::cout << "overloadTest(nullptr)= " <<  overloadTest(nullptr)<< std::endl;

  std::cout << std::endl;

}

