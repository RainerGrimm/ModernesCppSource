// lambdaAndAuto.cpp

#include <functional>
#include <iostream>

double divMe(double a, double b){
  return double(a/b);
}

using namespace std::placeholders;

int main(){

  std::cout << '\n';

  // invoking the function object directly
  std::cout << "1/2.0= " << [](int a, int b){ return divMe(a, b); }(1, 2.0) << '\n';

  // placeholders for both arguments
  auto myDivBindPlaceholder= [](int a, int b){ return divMe(a, b); };
  std::cout << "1/2.0= " << myDivBindPlaceholder(1, 2.0) << '\n';

  // placeholders for both arguments, swap the arguments
  auto myDivBindPlaceholderSwap= [](int a, int b){ return divMe(b, a); };
  std::cout << "1/2.0= " << myDivBindPlaceholderSwap(2.0, 1) << '\n';

  // placeholder for the first argument
  auto myDivBind1St= [](int a){ return divMe(a, 2.0); };
  std::cout<< "1/2.0= " << myDivBind1St(1) << '\n';

  // placeholder for the second argument
  auto myDivBind2Nd= [](int b){ return divMe(1, b); };
  std::cout << "1/2.0= " << myDivBind2Nd(2.0) << '\n';

  std::cout << '\n';

}