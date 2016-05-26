// asyncLazy.cpp

#include <chrono>
#include <future>
#include <iostream>

int main(){

  std::cout << std::endl;

  auto begin= std::chrono::system_clock::now();

  auto asyncLazy=std::async(std::launch::deferred,[]{ return  std::chrono::system_clock::now();});

  auto asyncEager=std::async( std::launch::async,[]{ return  std::chrono::system_clock::now();});

  std::this_thread::sleep_for(std::chrono::seconds(1));

  auto lazyStart= asyncLazy.get() - begin;
  auto eagerStart= asyncEager.get() - begin;

  auto lazyDuration= std::chrono::duration<double>(lazyStart).count();
  auto eagerDuration=  std::chrono::duration<double>(eagerStart).count();

  std::cout << "asyncLazy evaluated after : " << lazyDuration << " seconds." << std::endl;
  std::cout << "asyncEager evaluated after: " << eagerDuration << " seconds." << std::endl;

  std::cout << std::endl;

}