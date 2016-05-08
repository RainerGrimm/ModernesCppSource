// singletonCallOnce.cpp

#include <iostream>
#include <mutex>

class MySingleton{

  private:
    static std::once_flag initInstanceFlag;
    static MySingleton* instance;
    MySingleton()= default;
    ~MySingleton()= default;

  public:
    MySingleton(const MySingleton&)= delete;
    MySingleton& operator=(const MySingleton&)= delete;

    static MySingleton* getInstance(){
      std::call_once(initInstanceFlag,MySingleton::initSingleton);
      return instance;
    }

    static void initSingleton(){
      instance= new MySingleton();
    }
};

MySingleton* MySingleton::instance= nullptr;
std::once_flag MySingleton::initInstanceFlag;


int main(){

  std::cout << std::endl;

  std::cout << "MySingleton::getInstance(): "<< MySingleton::getInstance() << std::endl;
  std::cout << "MySingleton::getInstance(): "<< MySingleton::getInstance() << std::endl;

  std::cout << std::endl;

}