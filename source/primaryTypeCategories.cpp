//  primaryTypeCategories.cpp

#include <iostream>
#include <type_traits>

struct A{
  int a;
  int f(int){return 2011;}
};

enum E{
  e= 1,
};

union U{
  int u;
};


int main(){
  
  std::cout <<  std::boolalpha <<  std::endl;

  std::cout << std::is_void<void>::value << std::endl;
  std::cout << std::is_integral<short>::value << std::endl;
  std::cout << std::is_floating_point<double>::value << std::endl;
  std::cout << std::is_array<int [] >::value << std::endl;
  std::cout << std::is_pointer<int*>::value << std::endl;
  std::cout << std::is_reference<int&>::value << std::endl;
  std::cout << std::is_member_object_pointer<int A::*>::value <<  std::endl;
  std::cout << std::is_member_function_pointer<int (A::*)(int)>::value << std::endl;
  std::cout << std::is_enum<E>::value << std::endl;
  std::cout << std::is_union<U>::value << std::endl;
  std::cout << std::is_class<std::string>::value << std::endl;
  std::cout << std::is_function<int * (double)>::value << std::endl;	
  std::cout << std::is_lvalue_reference<int&>::value << std::endl;
  std::cout << std::is_rvalue_reference<int&&>::value << std::endl;
  
  std::cout <<  std::endl;

}
		