#include <iostream>
#include <type_traits>

struct A {
  int a;
  int f(int) { return 2011; }
};

enum E {
  e= 1,
};

union U {
  int u;
};


int main() {

  using namespace std;
  
  cout <<  boolalpha <<  '\n';

  cout << is_void<void>::value << '\n';                               // true                           
  cout << is_integral<short>::value << '\n';                          // true
  cout << is_floating_point<double>::value << '\n';                   // true
  cout << is_array<int []>::value << '\n';                            // true
  cout << is_pointer<int*>::value << '\n';                            // true
  cout << is_null_pointer<nullptr_t>::value << '\n';                  // true
  cout << is_member_object_pointer<int A::*>::value <<  '\n';         // true
  cout << is_member_function_pointer<int (A::*)(int)>::value << '\n'; // true
  cout << is_enum<E>::value << '\n';                                  // true
  cout << is_union<U>::value << '\n';                                 // true 
  cout << is_class<string>::value << '\n';                            // true
  cout << is_function<int * (double)>::value << '\n';                 // true	
  cout << is_lvalue_reference<int&>::value << '\n';                   // true
  cout << is_rvalue_reference<int&&>::value << '\n';                  // true
  
}
