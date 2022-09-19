// singleton.cpp

#include <iostream>

class MySingleton{

  private:
    static MySingleton* instance;
    MySingleton() = default;
    ~MySingleton() = default;

  public:
    MySingleton(const MySingleton&) = delete;
    MySingleton& operator=(const MySingleton&) = delete;

    static MySingleton* getInstance(){
      if ( !instance ){
        instance = new MySingleton();
      }
      return instance;
    }
};

MySingleton* MySingleton::instance = nullptr;


int main(){

  std::cout << '\n';

  std::cout << "MySingleton::getInstance(): "<< MySingleton::getInstance() << '\n';
  std::cout << "MySingleton::getInstance(): "<< MySingleton::getInstance() << '\n';

  std::cout << '\n';

}
