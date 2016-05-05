// removeConst.cpp

#include <iostream>
#include <string>
#include <type_traits>

namespace rgr{
  
  template<class T, class U>
  struct is_same : std::false_type {};
 
  template<class T>
  struct is_same<T, T> : std::true_type {};

  template< class T > 
  struct remove_const{ 
    typedef T type; 
  };

  template< class T > 
  struct remove_const<const T> { 
    typedef T type; 
  };
}


int main(){
  
  std::cout << std::boolalpha << std::endl;
  
  std::cout << std::is_same<int,std::remove_const<const int>::type>::value << std::endl;
  std::cout << rgr::is_same<int,rgr::remove_const<const int>::type>::value << std::endl;
  
  typedef rgr::remove_const<double>::type myDouble;
  std::cout << rgr::is_same<double,myDouble>::value << std::endl;
  
  typedef rgr::remove_const<const std::string>::type myString;
  std::cout << rgr::is_same<std::string,myString>::value << std::endl;
  
  typedef rgr::remove_const<std::add_const<int>::type>::type myInt;
  std::cout << rgr::is_same<int,myInt>::value << std::endl;
  
  std::cout << std::endl;
  
}
