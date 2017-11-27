// typeEnum.cpp

#include <iostream>

enum class Colour1{
  red,
  blue,
  green
};
 
enum struct Colour2: char {
  red,
  blue,
  green
};

int main(){

  std::cout << sizeof(Colour1) << std::endl;  // 1
  std::cout << sizeof(Colour2) << std::endl;  // 4

}
