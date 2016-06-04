// array.cpp

#include <algorithm>
#include <array>
#include <iostream>

int main(){

  std::cout << std::endl;

  // output the array
  std::array <int,8> array1{1,2,3,4,5,6,7,8};
  std::for_each( array1.begin(),array1.end(),[](int v){std::cout << v << " ";});

  std::cout << std::endl;

  // calculate the sum of the array by using a global variable
  int sum = 0;
  std::for_each(array1.begin(), array1.end(),[&sum](int v) { sum += v; });
  std::cout << "sum of array{1,2,3,4,5,6,7,8}: " << sum << std::endl;

  // change each array element to the second power
  std::for_each(array1.begin(), array1.end(),[](int& v) { v=v*v; });
  std::for_each( array1.begin(),array1.end(),[](int v){std::cout << v << " ";});
  std::cout << std::endl;

  std::cout << std::endl;

}
