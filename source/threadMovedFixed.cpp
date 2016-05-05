// threadMovedFixed.cpp

#include <iostream> 
#include <thread> 
#include <utility>

int main(){ 

  std::thread t([]{std::cout << std::this_thread::get_id() << std::endl;}); 
  std::thread t2([]{std::cout << std::this_thread::get_id() << std::endl;}); 
  
  t.join();
  t= std::move(t2); 
  t.join(); 
  
  std::cout << "\n";
  std::cout << std::boolalpha << "t2.joinable(): " << t2.joinable() << std::endl;

}