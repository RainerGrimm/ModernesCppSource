// placeholders.cpp

#include <iostream>
#include <typeinfo>

template<typename T>
concept bool Integral(){
  return std::is_integral<T>::value;
}

void overload(auto t){
  std::cout << "auto : " << t << std::endl;
}

void overload(Integral t){
  std::cout << "Integral : " << t << std::endl;
}

void overload(long t){
  std::cout << "long : " << t << std::endl;
}
  
void twoTypes(auto a, auto b){
  std::cout << typeid(a).name() << std::endl;
  std::cout << typeid(b).name() << std::endl;
}


int main(){
  
  std::cout << std::endl;
  
  overload(3.14);
  overload(2010);
  overload(2020l);
  
  std::cout << std::endl;
  
  twoTypes(2010, 3.14); 
  
  std::cout << std::endl;

}
