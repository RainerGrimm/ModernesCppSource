// uniqueDuration.cpp

#include <chrono>
#include <iostream>
#include <memory>

static const long long numInt= 100000000;

int main(){

  auto start = std::chrono::system_clock::now();

  for ( long long i= 0; i < numInt; ++i){
    std::unique_ptr<int> tmp(new int(i));
  }

  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time unique_ptr: " << dur.count() << " seconds" << std::endl;

}
