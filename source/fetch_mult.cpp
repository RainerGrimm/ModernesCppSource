// fetch_mult.cpp

#include <atomic>
#include <iostream>

template <typename T>
T fetch_mult(std::atomic<T>& shared, T mult){
  T oldValue= shared.load();
  while (!shared.compare_exchange_strong(oldValue, oldValue * mult));
  return oldValue;
}

int main(){
  std::atomic<int> myInt{5};
  std::cout << myInt << std::endl;          
  fetch_mult(myInt,5);
  std::cout << myInt << std::endl;         
}
