// lazy.cpp

#include <iostream>

template<class T> 
struct Lazy{
    void func() { std::cout << "func" << std::endl;}
    void func2(); // not defined
};

int main(){
  
  std::cout << std::endl;
    
  Lazy<int> lazy;
  lazy.func();
  
  std::cout << std::endl;
    
}
