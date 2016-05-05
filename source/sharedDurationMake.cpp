// sharedDurationMake.cpp

#include <chrono>
#include <iostream>
#include <memory>

static const long long numInt= 100000000;

int main(){

  auto start = std::chrono::system_clock::now();

  for ( long long i= 0; i < numInt; ++i){
    std::shared_ptr<int> tmp(std::make_shared<int>(i));
  }

  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time make_shared: " << dur.count() << " seconds" << std::endl;

}
