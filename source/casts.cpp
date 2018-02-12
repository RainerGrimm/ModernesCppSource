// casts.cpp

#include <iostream>

int main(){

  double d = 2;
  auto p = (long*)&d;
  auto q = (long long*)&d;
  std::cout << d << ' ' << *p << ' ' << *q << '\n';
  
}
