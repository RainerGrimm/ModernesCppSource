// traitsPrimary.cpp

#include <iostream>
#include <type_traits>

using namespace std;

template <typename T>
void getPrimaryTypeCategory(){

  cout << boolalpha << endl;

  cout << "is_void<T>::value: " << is_void<T>::value << endl;
  cout << "is_integral<T>::value: " << is_integral<T>::value << endl;
  cout << "is_floating_point<T>::value: " << is_floating_point<T>::value << endl;
  cout << "is_array<T>::value: " << is_array<T>::value << endl;
  cout << "is_pointer<T>::value: " << is_pointer<T>::value << endl;
  cout << "is_null_pointer<T>::value: " << is_null_pointer<T>::value << endl;
  cout << "is_member_object_pointer<T>::value: " << is_member_object_pointer<T>::value << endl;
  cout << "is_member_function_pointer<T>::value: " << is_member_function_pointer<T>::value << endl;
  cout << "is_enum<T>::value: " << is_enum<T>::value << endl;
  cout << "is_union<T>::value: " << is_union<T>::value << endl;
  cout << "is_class<T>::value: " << is_class<T>::value << endl;
  cout << "is_function<T>::value: " << is_function<T>::value << endl;
  cout << "is_lvalue_reference<T>::value: " << is_lvalue_reference<T>::value << endl;
  cout << "is_rvalue_reference<T>::value: " << is_rvalue_reference<T>::value << endl;

  cout << endl;

}

int main(){
    
    getPrimaryTypeCategory<void>();              // (1)
    getPrimaryTypeCategory<short>();             // (1)
    getPrimaryTypeCategory<double>();
    getPrimaryTypeCategory<int []>();
    getPrimaryTypeCategory<int*>();
    getPrimaryTypeCategory<std::nullptr_t>();
    struct A{
        int a;
        int f(double){return 2011;}
    };
    getPrimaryTypeCategory<int A::*>();
    getPrimaryTypeCategory<int (A::*)(double)>();
    enum E{
        e= 1,
    };
    getPrimaryTypeCategory<E>();
    union U{
      int u;
    };
    getPrimaryTypeCategory<U>();
    getPrimaryTypeCategory<string>();
    getPrimaryTypeCategory<int * (double)>();
    getPrimaryTypeCategory<int&>();              // (2)         
    getPrimaryTypeCategory<int&&>();             // (2)
    
}
