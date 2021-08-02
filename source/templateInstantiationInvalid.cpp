#include <iostream>
#include <vector>

template <int Nom, int Denom>
class Rational{
public:
    int getFloor(){
        return Nom / Denom; 
    }
};
    
// template int Rational<5, 0>::getFloor();

int main(){

  std::cout << '\n';
  
  Rational<5, 3> rat1;
  std::cout << "rat1.getFloor(): " << rat1.getFloor() << '\n';


  Rational<5, 0> rat2;
  //std::cout << "rat2.getFloor(): " << rat2.getFloor() << '\n';
  
  std::cout << '\n';
  
}
