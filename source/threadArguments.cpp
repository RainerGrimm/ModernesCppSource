// threadArguments.cpp

#include <chrono>
#include <iostream>
#include <thread>

class Sleeper{
  public:
    Sleeper(int& i_):i{i_}{};
    void operator() (int k){
      for (unsigned int j= 0; j <= 5; ++j){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        i += k;
      }
      std::cout << std::this_thread::get_id() << std::endl;
    }
  private:
    int& i;
};


int main(){

  std::cout << std::endl;

  int valSleeper= 1000;
  std::thread t(Sleeper(valSleeper),5);
  t.detach();
  std::cout << "valSleeper = " << valSleeper << std::endl;

  std::cout << std::endl;

}