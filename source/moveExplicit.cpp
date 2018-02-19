// moveExplicit.cpp

#include <future>
#include <iostream>
#include <thread>
#include <utility>

void product(std::promise<int>&& intPromise, int a, int b){     // (2)
  intPromise.set_value(a * b);
}

int main(){

  int a= 20;
  int b= 10;

  // define the promises
  std::promise<int> prodPromise;

  // get the futures
  std::future<int> prodResult= prodPromise.get_future();

  // calculate the result in a separat thread
  std::thread prodThread(product,std::move(prodPromise), a, b);   // (1)
 
  // get the result
  std::cout << "20 * 10 = " << prodResult.get() << std::endl;     // 200
  
  prodThread.join();

}
