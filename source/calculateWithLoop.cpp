// calculateWithLoop.cpp

#include <chrono>
#include <iostream>
#include <random>
#include <vector>

constexpr long long size= 100000000;

int main(){

  std::cout << std::endl;

  std::vector<int> randValues;
  randValues.reserve(size);

  // random values
  std::random_device seed;
  std::mt19937 engine(seed());
  std::uniform_int_distribution<> uniformDist(1,10);
  for ( long long i=0 ; i< size ; ++i) randValues.push_back(uniformDist(engine));
 
  auto start = std::chrono::system_clock::now();
  
  unsigned long long add= {};
  for (auto n: randValues) add+= n;
 
  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "Time for addition " << dur.count() << " seconds" << std::endl;
  std::cout << "Result: " << add << std::endl;

  std::cout << std::endl;

}