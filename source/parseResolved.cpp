// parseResolved.cpp

#include <iostream>
#include <typeinfo>

struct MyInt{
  MyInt(int i):i(i){}
  MyInt():i(0){}
  int i;
};

MyInt myFunction();

int main(){

  MyInt myInt(2011);
  MyInt myInt2();
  
  std::cout << typeid(myInt2).name() << std::endl;
  std::cout << typeid(myFunction).name() << std::endl;

}
  
  
