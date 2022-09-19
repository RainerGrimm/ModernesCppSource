// singletonMeyer.cpp

#include <iostream>

class MeyersSingleton{

  private:

    MeyersSingleton() = default;
    ~MeyersSingleton() = default;

  public:

    MeyersSingleton(const MeyersSingleton&) = delete;
    MeyersSingleton& operator = (const MeyersSingleton&) = delete;

    static MeyersSingleton& getInstance(){
      static MeyersSingleton instance;
      return instance;
    }
};


int main() {

  std::cout << '\n';

  std::cout << "&MeyersSingleton::getInstance(): "<< &MeyersSingleton::getInstance() << '\n';
  std::cout << "&MeyersSingleton::getInstance(): "<< &MeyersSingleton::getInstance() << '\n';

  std::cout << '\n';

}

