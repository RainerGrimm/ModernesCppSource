// scopedEnum.cpp

#include <iostream>

enum class ColourScoped{
  red,
  blue,
  green
};

void useMe(ColourScoped color){

  switch(color){
  case ColourScoped::red:
    std::cout << "ColourScoped::red" << std::endl;
    break;
  case ColourScoped::blue:
    std::cout << "ColourScoped::blue" << std::endl;
    break;
  case ColourScoped::green:
    std::cout << "ColourScoped::green" << std::endl;
    break;
  }

}


int main(){

  std::cout << std::endl;

  std::cout <<  static_cast<int>(ColourScoped::red) << std::endl;   // 0
  std::cout <<  static_cast<int>(ColourScoped::red) << std::endl;   // 0

  std::cout << std::endl;

  ColourScoped colour{ColourScoped::red};
  useMe(colour);                                                     // ColourScoped::red

  std::cout << std::endl;

}
