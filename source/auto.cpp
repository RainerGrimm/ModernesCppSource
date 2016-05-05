#include <vector>

int myAdd(int a,int b){ return a+b; }

int main(){

  // define an int-value
  int i= 5;                                  // explicit
  auto i1= 5;                                // auto

  // define a reference to an int
  int& b= i;                                 // explicit
  auto& b1= i;                               // auto

  // define a pointer to a function
  int (*add)(int,int)= myAdd;               // explicite
  auto add1= myAdd;                         // auto

  // iterate through a vector
  std::vector<int> vec;
  for (std::vector<int>::iterator it= vec.begin(); it != vec.end(); ++it){} 
  for (auto it1= vec.begin(); it1 != vec.end(); ++it1) {}

}
