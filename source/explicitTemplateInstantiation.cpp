// explicitTemplateInstantiation.cpp

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class MyClass{
 public:
    MyClass(T t) { }
    std::string getType() const {
        return typeid(T).name();
    }
};

template<typename T>
bool isSmaller(T fir, T sec){
  return fir < sec;
}
 
template class std::vector<int>;                       // (1)
template bool std::vector<double>::empty() const;      // (2)

template class MyClass<int>;                           // (3)
template std::string MyClass<double>::getType() const; // (4)

template bool isSmaller(int, int);                     // (5)
template bool isSmaller<double>(double, double);       // (6)

int main(){

  std::cout << '\n';
  
  std::cout << std::boolalpha;
  
  std::vector vec{1, 2, 3, 4, 5};
  std::cout << "vec.size(): " << vec.size() << '\n';
  
  MyClass myClass(5);
  std::cout << "myClass.getType(): " << myClass.getType() << '\n';
  
  std::cout << '\n';
  
  std::cout << "isSmaller(5, 10): " 
            << isSmaller(5,10) << '\n';
  std::cout << "isSmaller<double>(5.5f, 6.5): " 
            << isSmaller<double>(5.5f, 6.5) << '\n';
  
  std::cout << '\n';
  
}
