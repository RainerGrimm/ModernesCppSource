// virtualInitialisation.cpp

#include <iostream>
#include <memory>

class Base{
protected:
  Base() = default;
public:
  virtual void f(){                                            // (1)
    std::cout << "Base called" << std::endl;                   
  }
  template<class T>                                              
  static std::unique_ptr<T> CreateMe(){                        // (2) 
    auto uniq = std::make_unique<T>();
    uniq->f();                                                 // (3)
    return uniq;
  }
  virtual ~Base() = default;                                   // (4)
};

struct Derived: Base{
  virtual void f(){
    std::cout << "Derived called" << std::endl;
  }
};


int main(){
  
  std::cout << std::endl;
  
  std::unique_ptr<Base> base = Derived::CreateMe<Derived>();   // (5)
  
  std::cout << std::endl;
  
};
