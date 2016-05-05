// enumClassic.cpp

#include <iostream>

int main(){
	
  std::cout << std::endl;
	
  enum Colour{red= 0,green= 2,blue};
  
  std::cout << "red: " << red << std::endl;
  std::cout << "green: " << green << std::endl;
  std::cout << "blue: " << blue << std::endl;
  
  int red2= red;
  
  std::cout << "red2: " << red2 << std::endl;
  
  // int red= 5;  ERROR
  
}