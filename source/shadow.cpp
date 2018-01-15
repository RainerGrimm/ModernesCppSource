// shadow.cpp

#include <iostream>

int shadow(bool cond){
  int d = 0;
  if (cond){
    d = 1;
  }
  else {
    int d = 2;
    d = 3;
  }
  return d;
}

int main(){

    std::cout << std::endl;
    
    std::cout << "shadow(true): " << shadow(true) << std::endl;      
    std::cout << "shadow(false): " << shadow(false) << std::endl;     

    std::cout << std::endl;
    
}
