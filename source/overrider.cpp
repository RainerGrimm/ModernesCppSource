// overrider.cpp

#include <iostream>

class Base {
public:
    virtual int multiply(int value, int factor = 2) = 0;
};

class Derived : public Base {
public:
  int multiply(int value, int factor = 10) override {
    return factor * value;
  }
};

int main(){

  std::cout << std::endl;

  Derived d;
  Base& b = d;

  std::cout << "b.multiply(10): " << b.multiply(10) << std::endl; 
  std::cout << "d.multiply(10): " << d.multiply(10) << std::endl;  

  std::cout << std::endl;

}
