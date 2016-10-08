// init.cpp

#include <iostream>
#include <string>
 
struct T1 {};
 
struct T2{
    int mem;     // Not ok: indeterminate value
 public:
    T2() {} 
};
 
int n;          //  ok: initialized to 0
 
int main(){
  
  std::cout << std::endl;
  
  int n;               // Not ok: indeterminate value
  std::string s;       // ok: Invocation of the default constructor; initialized to "" 
  T1 t1;               // ok: Invocation of the default constructor 
  T2 t2;               // ok: Invocation of the default constructor
    
  std::cout << "::n " << ::n << std::endl;
  std::cout << "n: " << n << std::endl;
  std::cout << "s: " << s << std::endl;
  std::cout << "T2().mem: " << T2().mem << std::endl;
  
  std::endl;
                      
}