// nakedUnion.cpp

#include <iostream>

union Value {
    int i;
    double d;
};

int main(){
  
  std::cout << std::endl;

  Value v;
  v.d = 987.654;  // v holds a double
  std::cout << "v.d: " << v.d << std::endl;     
  std::cout << "v.i: " << v.i << std::endl;      // (1)

  std::cout << std::endl;

  v.i = 123;     // v holds an int
  std::cout << "v.i: " << v.i << std::endl;
  std::cout << "v.d: " << v.d << std::endl;      // (2)
  
  std::cout << std::endl;

}
