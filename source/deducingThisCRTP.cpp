// deducingThisCRTP.cpp

#include <iostream>

struct Base{                                            // (1)
  template <typename Self>
  void interface(this Self&& self){
    self.implementation();
  }
  void implementation(){
    std::cout << "Implementation Base" << '\n';
  }
};

struct Derived1: Base{
  void implementation(){
    std::cout << "Implementation Derived1" << '\n';
  }
};

struct Derived2: Base{
  void implementation(){
    std::cout << "Implementation Derived2" << '\n';
  }
};

struct Derived3: Base{};

template <typename T>
void execute(T& base){
    base.interface();                                 // (2)
}

int main(){
  
  std::cout << '\n';
  
  Derived1 d1;                                        // (3)
  execute(d1);
    
  Derived2 d2;                                        // (4)
  execute(d2);
  
  Derived3 d3;                                        // (5)
  execute(d3);
  
  std::cout << '\n';
  
}
