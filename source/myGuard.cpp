// myGuard.cpp

#include <mutex>
#include <iostream>

template <typename T>
class MyGuard{
  T& myMutex;
  public:
    MyGuard(T& m):myMutex(m){
      myMutex.lock();
	  std::cout << "lock" << std::endl;
    }
    ~MyGuard(){
	  myMutex.unlock();
      std::cout << "unlock" << std::endl;
    }
};

int main(){
	
  std::cout << std::endl;
	
  std::mutex m;
  MyGuard<std::mutex> {m};                        // (1)
  std::cout << "CRITICAL SECTION" << std::endl;   // (2)
  
  std::cout << std::endl;

}                                                 // (3)