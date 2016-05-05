// macro.cpp

#include <iostream>

#define  absMacro(i) ( (i) >= 0 ? (i) : -(i) )

inline int absFunction(int i){
  return i >= 0 ? i : -i;
}

int func(){ 
  std::cout << "func called" << std::endl;
  return 0;
}


int main(){
  
  std::cout << std::endl;
  
  auto i(0);
  auto res = absMacro(++i);   
  std::cout << "res: " << res << std::endl;
  absMacro(func());
  
  std::cout << std::endl;
  
  i=0;
  res= absFunction(++i);     
  std::cout << "res: " << res << std::endl;
  absFunction(func());
  
  std::cout << std::endl;
  
}