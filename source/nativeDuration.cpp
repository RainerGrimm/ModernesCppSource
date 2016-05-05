// nativeDuration.cpp

#include <chrono>
#include <iostream>

static const long long numInt= 100000000;

int main(){

  auto start = std::chrono::system_clock::now();

  for ( long long i=0 ; i < numInt; ++i){
    int* tmp(new int(i));
    delete tmp;
  }

  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time native: " << dur.count() << " seconds" << std::endl;

}
