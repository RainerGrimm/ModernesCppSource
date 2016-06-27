// perfectForwarding1.cpp

#include <iostream>

template <typename T,typename Arg>
T create(Arg& a){
  return T(a);
}

int main(){
    
  std::cout << std::endl;

  // Lvalues
  int five=5;
  int myFive= create<int>(five);
  std::cout << "myFive: "  << myFive << std::endl;

  // Rvalues
  int myFive2= create<int>(5);
  std::cout << "myFive2: " << myFive2 << std::endl;

  std::cout << std::endl;

}
