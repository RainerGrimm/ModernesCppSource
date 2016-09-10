// factorial.cpp

#include <iostream>

template <int N>
struct Factorial{
  static int const value= N * Factorial<N-1>::value;
};

template <>
  struct Factorial<1>{
  static int const value = 1;
};

int main(){
    
  std::cout << std::endl;

  std::cout << "Factorial<4>::value: " << Factorial<4>::value << std::endl;
  std::cout << "Factorial<5>::value: " << Factorial<5>::value << std::endl;
  
  std::cout << std::endl;

}
