// overloadOperatorNewAndDelete2.cpp

#include "myNew4.hpp"
// #include "myNew5.hpp"

#define new new(__FILE__, __LINE__)

#include <iostream>
#include <new>
#include <string>

class MyClass{
  float* p= new float[100];
};

class MyClass2{
  int five= 5;
  std::string s= "hello";
};

int main(){
    
    int* myInt= new int(1998);
    double* myDouble= new double(3.14);
    double* myDoubleArray= new double[2]{1.1,1.2};
    
    MyClass* myClass= new MyClass;
    MyClass2* myClass2= new MyClass2;
    
    delete myDouble;
    delete [] myDoubleArray;
    delete myClass;
    delete myClass2;
    
    dummyFunction();
    
    getInfo();
    
}
    
