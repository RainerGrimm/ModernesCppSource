// implicitConversion.cpp

#include <iostream>
#include <string>


struct MyHouse{
  MyHouse() = default;
  MyHouse(const std::string& fam): family(fam){}
	
  operator bool(){ return not family.empty(); }               // (1)
  // explicit operator bool(){ return not family.empty(); }   // (2)
	
  std::string family = "";
};

int main(){
	
  std::cout << std::boolalpha << std::endl;
	
  MyHouse firstHouse;
  if (not firstHouse){                                        // (3)
    std::cout << "firstHouse is already sold." << std::endl;
  };
	
  MyHouse secondHouse("grimm");                               // (4)
  if (secondHouse){
    std::cout << "Grimm bought secondHouse." << std::endl;
  }
	
  std::cout << std::endl;
	
  int myNewHouse = firstHouse + secondHouse;                  // (5)
  auto myNewHouse2 = (20 * firstHouse - 10 * secondHouse) / secondHouse;

  std::cout << "myNewHouse: " << myNewHouse << std::endl;
  std::cout << "myNewHouse2: " << myNewHouse2 << std::endl;
	
  std::cout << std::endl;
}
