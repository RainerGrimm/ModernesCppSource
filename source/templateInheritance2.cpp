// templateInheritance2.cpp

#include <iostream>

template <typename T>
class Base{
public:
  void func1() const {
    std::cout << "func1()" << std::endl;
  }
  void func2() const {
    std::cout << "func2()" << std::endl;
  }
  void func3() const {
    std::cout << "func3()" << std::endl;
  }
};

template <typename T>
class Derived: public Base<T>{
public:
  using Base<T>::func2;              // (2)
  void callAllBaseFunctions(){

    this->func1();                   // (1)
    func2();                         // (2)
    Base<T>::func3();                // (3)

  }
};


int main(){

  std::cout << std::endl;

  Derived<int> derived;
  derived.callAllBaseFunctions();

  std::cout << std::endl;

}
