// stringAndVector.cpp

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void showInfo(const T& t,const std::string& name){

  std::cout << name << " t.size(): " << t.size() << std::endl;
  std::cout << name << " t.capacity(): " << t.capacity() << std::endl;

}

int main(){
    
  std::cout << std::endl;

  std::string str;
  std::vector<int> vec;
  
  std::cout << "Maximal size: " << std::endl;
  std::cout << "str.max_size(): " << str.max_size() << std::endl;
  std::cout << "vec.max_size(): " << vec.max_size() << std::endl;
  std::cout << std::endl;
  
  std::cout << "Empty string and vector: " << std::endl;
  showInfo(str,"String");
  showInfo(vec,"Vector");
  std::cout << std::endl;
  
  
  std::cout << "Initialized with five values: " << std::endl;
  str= {"12345"};
  vec= {1,2,3,4,5};
  showInfo(str,"String");
  showInfo(vec,"Vector");
  std::cout << std::endl;
  
  std::cout << "Added four additional values: " << std::endl;
  str += "6789";
  vec.insert(vec.end(),{6,7,8,9});
  showInfo(str,"String");
  showInfo(vec,"Vector");
  std::cout << std::endl;
  
  
  std::cout << "Resized to 30 values: " << std::endl;
  str.resize(30);
  vec.resize(30);
  showInfo(str,"String");
  showInfo(vec,"Vector");
  std::cout << std::endl;

  std::cout << "Reserved space for at least 1000 values: " << std::endl;
  str.reserve(1000);
  vec.reserve(1000);
  showInfo(str,"String");
  showInfo(vec,"Vector");
  std::cout << std::endl;
  
  std::cout << "Shrinked to the current size: " << std::endl;
  str.shrink_to_fit();
  vec.shrink_to_fit();
  showInfo(str,"String");
  showInfo(vec,"Vector");
  std::cout << std::endl;

}