// bindAndFunction.cpp

#include <functional>
#include <iostream>

double divMe(double a, double b){
  return double(a/b);
}

using namespace std::placeholders;

int main(){

  std::cout << std::endl;

  // invoking the function object directly
  std::cout << "1/2.0= " << std::bind(divMe, 1, 2.0)() << std::endl;

  // placeholders for both arguments
  std::function<double(double, double)> myDivBindPlaceholder= std::bind(divMe, _1, _2);
  std::cout << "1/2.0= " << myDivBindPlaceholder(1, 2.0) << std::endl;

  // placeholders for both arguments, swap the arguments
  std::function<double(double, double)> myDivBindPlaceholderSwap= std::bind(divMe, _2, _1);
  std::cout << "1/2.0= " << myDivBindPlaceholderSwap(2.0, 1) << std::endl;

  // placeholder for the first argument
  std::function<double(double)> myDivBind1St= std::bind(divMe, _1, 2.0);
  std::cout<< "1/2.0= " << myDivBind1St(1) << std::endl;

  // placeholder for the second argument
  std::function<double(double)> myDivBind2Nd= std::bind(divMe, 1.0, _1);
  std::cout << "1/2.0= " << myDivBind2Nd(2.0) << std::endl;

  std::cout << std::endl;

}