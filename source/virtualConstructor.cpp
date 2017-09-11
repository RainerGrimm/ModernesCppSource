// virtualConstructor.cpp

#include <iostream>

struct Base{
  Base(){
    f();
  }
  virtual void f(){
    std::cout << "Base called" << std::endl;
  }
};

struct Derived: Base{
  virtual void f(){
    std::cout << "Derived called" << std::endl;
  }
};

int main(){
  
  std::cout << std::endl;
  
  Derived d;         
  
  std::cout << std::endl;
  
};
