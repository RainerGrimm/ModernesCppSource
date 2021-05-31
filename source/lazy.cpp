// lazy.cpp

#include <iostream>

template<class T> 
struct Lazy{
    void func() { std::cout << "func\n"; }
    void func2(); // not defined
};

int main(){
  
  std::cout << '\n';
    
  Lazy<int> lazy;
  lazy.func();
  
  std::cout << '\n';
    
}
