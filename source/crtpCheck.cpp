#include <iostream>

template <typename Derived>
struct Base{
  void interface(){
    static_cast<Derived*>(this)->implementation();
  }
private:
    Base() = default;
    friend Derived;
};

struct Derived1: Base<Derived1>{
  void implementation(){
    std::cout << "Implementation Derived1" << '\n';
  }
};

struct Derived2: Base<Derived1>{
  void implementation(){
    std::cout << "Implementation Derived1" << '\n';
  }
};

template <typename T>
void execute(T& base){
    base.interface();
}

int main(){
  
  std::cout << '\n';
  
  Derived1 d1;
  execute(d1);
    
  Derived2 d2;
  execute(d2);
  
  std::cout << '\n';
  
}