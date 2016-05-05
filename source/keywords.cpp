// keywords.cpp

#include <iostream>

void override(){ std::cout << "override" << std::endl; }

int main(){

  std::cout << std::endl;

  override();
  
  auto final(2011);
  std::cout << "final: " << final << std::endl;

  std::cout << std::endl;

}