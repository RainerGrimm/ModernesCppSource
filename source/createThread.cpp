// createThread.cpp

#include <iostream>
#include <thread>

void helloFunction(){
  std::cout << "Hello C++11 from function." << std::endl;
}

class HelloFunctionObject  {
  public:
    void operator()() const {
      std::cout << "Hello C++11 from a function object." << std::endl;
    }
};


int main(){

  std::cout << std::endl;

  // thread executing helloFunction
  std::thread t1(helloFunction);

  // thread executing helloFunctionObject
  HelloFunctionObject helloFunctionObject;
  std::thread t2(helloFunctionObject);

  // thread executing lambda function
  std::thread t3([]{std::cout << "Hello C++11 from lambda function." << std::endl;});

  // ensure that t1, t2 and t3 have finished before main terminates
  t1.join();
  t2.join();
  t3.join();

  std::cout << std::endl;

};

