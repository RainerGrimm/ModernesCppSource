// threadWithoutJoin.cpp

#include <iostream>
#include <thread>

int main(){

  std::thread t([]{std::cout << std::this_thread::get_id() << std::endl;});

}