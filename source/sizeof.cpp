// sizeof.cpp

#include <iostream>
#include <array>
#include <vector>
 
 
int main(){
  
  std::cout << std::endl;
  
  std::cout << "sizeof(int)= " << sizeof(int) << std::endl;
  
  std::cout << std::endl;
  
  int cArr[10]= {1,2,3,4,5,6,7,8,9,10};
  
  std::array<int,10> cppArr={1,2,3,4,5,6,7,8,9,10};
  
  std::vector<int> cppVec={1,2,3,4,5,6,7,8,9,10};
  
  std::cout << "sizeof(cArr)= " << sizeof(cArr) << std::endl;  
  
  std::cout << "sizeof(cppArr)= " << sizeof(cppArr) << std::endl;
  
  std::cout << "sizeof(cppVec) = "   << sizeof(cppVec) + sizeof(int)*cppVec.capacity() << std::endl;
  std::cout << "               = sizeof(cppVec): " << sizeof(cppVec) << std::endl;
  std::cout << "               + sizeof(int)* cppVec.capacity(): "   << sizeof(int)* cppVec.capacity() << std::endl;

  std::cout << std::endl;
  
}