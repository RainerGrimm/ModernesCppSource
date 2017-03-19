// conceptsDefintionEqual.cpp

#include <iostream>

template<typename T>
concept bool Equal(){
  return requires(T a, T b) {
    { a == b } -> bool;
    { a != b } -> bool;
  };
}

bool areEqual(Equal a, Equal b){
  return a == b;
}

/*

struct WithoutEqual{
  bool operator==(const WithoutEqual& other) = delete;
};

struct WithoutUnequal{
  bool operator!=(const WithoutUnequal& other) = delete;
};

*/

int main(){
  
  std::cout << std::boolalpha << std::endl;
  
  std::cout << "areEqual(1, 5): " << areEqual(1, 5) << std::endl;
  
  /*
  
  bool res = areEqual(WithoutEqual(),  WithoutEqual());
  
  bool res2 = areEqual(WithoutUnequal(),  WithoutUnequal());
  
  */
  
  std::cout << std::endl;
  
}
