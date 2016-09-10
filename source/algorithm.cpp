// algorithm.cpp

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main(){

  std::cout << std::endl;

  std::vector<int> myVec{1,2,3,4,5,6,7,8,9};

  std::cout << "original:         ";
  for (auto a: myVec) { std::cout << a << " ";}

  std::cout << "\n\n";
  
  std::transform(myVec.begin(),myVec.end(),myVec.begin(), [](int i){ return i*i; });

  std::cout << "std::transform:   ";
  for (auto a: myVec) { std::cout << a << " ";}
  
  std::cout << "\n\n";
  
  myVec={1,2,3,4,5,6,7,8,9};
  
  auto logicalEnd= std::remove_if(myVec.begin(),myVec.end(), [](int i){ return !((i < 3) or (i > 8)); });
  myVec.erase(logicalEnd,myVec.end());
  
  std::cout << "std::remove_if:   ";
  for (auto a: myVec) { std::cout << a << " ";}
  
  std::cout << "\n\n";
  
  myVec={1,2,3,4,5,6,7,8,9};
  
  std::cout << "std::accumulate:  ";
  auto fak= std::accumulate(myVec.begin(),myVec.end(),1,[](int fir, int sec){ return fir * sec; });
  std::cout << "fak(10): " << fak << std::endl;
  
  std::cout << std::endl;

}