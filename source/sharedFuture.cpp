// sharedFuture.cpp

#include <exception>
#include <future>
#include <iostream>
#include <thread>
#include <utility>

std::mutex coutMutex;

struct Div{

  void operator()(std::promise<int>&& intPromise, int a, int b){
    try{
      if ( b==0 ) throw std::runtime_error("illegal division by zero");
      intPromise.set_value(a/b);
    }
    catch (...){
      intPromise.set_exception(std::current_exception());
    }
  }

};

struct Requestor{

  void operator ()(std::shared_future<int> shaFut){

    // lock std::cout
    std::lock_guard<std::mutex> coutGuard(coutMutex);

    // get the thread id
    std::cout << "threadId(" << std::this_thread::get_id() << "): " ;

    // get the result
    try{
      std::cout << "20/10= " << shaFut.get() << std::endl;
    }
    catch (std::runtime_error& e){
      std::cout << e.what() << std::endl;
    }
  }

};

int main(){

  std::cout << std::endl;

  // define the promises
  std::promise<int> divPromise;

  // get the futures
  std::shared_future<int> divResult= divPromise.get_future();

  // calculate the result in a separat thread
  Div div;
  std::thread divThread(div,std::move(divPromise),20,10);

  Requestor req;
  std::thread sharedThread1(req,divResult);
  std::thread sharedThread2(req,divResult);
  std::thread sharedThread3(req,divResult);
  std::thread sharedThread4(req,divResult);
  std::thread sharedThread5(req,divResult);

  divThread.join();

  sharedThread1.join();
  sharedThread2.join();
  sharedThread3.join();
  sharedThread4.join();
  sharedThread5.join();

  std::cout << std::endl;

}