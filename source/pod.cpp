// pod.cpp

#include <iostream>
#include <type_traits>

struct Pod{
  int a;
};

struct NotPod{
    int i;
  private:
    int j;
};

int main(){

  std::cout << std::boolalpha << std::endl;
  
  std::cout << "std::is_pod<Pod>::value: " << std::is_pod<Pod>::value << std::endl;
  std::cout << "std::is_pod<NotPod>::value: " << std::is_pod<NotPod>::value << std::endl;
  
  std::cout << std::endl;
   
  std::cout << "std::is_trivial<NotPod>::value: " << std::is_trivial<NotPod>::value << std::endl;
  std::cout << "std::is_standard_layout<NotPod>::value: " << std::is_standard_layout<NotPod>::value << std::endl;
  
  std::cout << std::endl;
  
}