// associativeCompare.cpp

#include <chrono>
#include <iostream>
#include <map>
#include <random>
#include <unordered_map>

static const long long mapSize= 10000000;
static const long long accSize= 1000000;

int main(){

  std::cout << std::endl;

  std::map<int,int> myMap;
  std::unordered_map<int,int> myHash;

  for ( long long i=0; i < mapSize; ++i ){
    myMap[i]=i;
    myHash[i]= i;
  }

  std::vector<int> randValues;
  randValues.reserve(accSize);

  // random values
  std::random_device seed;
  std::mt19937 engine(seed());
  std::uniform_int_distribution<> uniformDist(0,mapSize);
  for ( long long i=0 ; i< accSize ; ++i) randValues.push_back(uniformDist(engine));

  auto start = std::chrono::system_clock::now();
  for ( long long i=0; i < accSize; ++i){
    myMap[randValues[i]];
  }
  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time for std::map: " << dur.count() << " seconds" << std::endl;

  auto start2 = std::chrono::system_clock::now();
  for ( long long i=0; i < accSize; ++i){
    myHash[randValues[i]];
  }
  std::chrono::duration<double> dur2= std::chrono::system_clock::now() - start2;
  std::cout << "time for std::unordered_map: " << dur2.count() << " seconds" << std::endl;

  std::cout << std::endl;

}
