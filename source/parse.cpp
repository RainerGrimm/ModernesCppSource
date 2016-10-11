// parse.cpp

#include <iostream>

struct MyInt{
  MyInt(int i):i(i){}
  MyInt():i(0){}
  int i;
};


int main(){

  MyInt myInt(2011);
  MyInt myInt2();
  
  std::cout << myInt.i << std::endl;
  std::cout << myInt2.i << std::endl;
 
}
  
  
