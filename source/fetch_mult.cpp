// fetch_mult.cpp

#include <atomic>
#include <iostream>

template <typename T>
T fetch_mult(std::atomic<T>& shared, T mult){                          // 1
  T oldValue = shared.load();                                          // 2
  while (!shared.compare_exchange_strong(oldValue, oldValue * mult));  // 3
  return oldValue;
}

int main(){
  std::atomic<int> myInt{5};
  std::cout << myInt << std::endl;          
  fetch_mult(myInt,5);
  std::cout << myInt << std::endl;         
}
