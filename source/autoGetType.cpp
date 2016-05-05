#include <get_type.hpp>

int main(){
  
  int i= 2011;
  const int i2= 2014;
  // GetType<decltype(i2)> myType;
  const int& i3= i2;
  // GetType<decltype(i3)> myType;
  
  auto a2= i2; 
  // GetType<decltype(a2)> myType;
  auto a3= i3;
  // GetType<decltype(a3)> myType;
  
}