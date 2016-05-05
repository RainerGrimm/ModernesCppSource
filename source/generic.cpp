// generic.cpp

#include <cstddef>
#include <iostream>
 
template<class P >
void functionTemplate(P p){
  int* a= p;
}
 
int main(){
  int* a= 0;           
  int* b= NULL;              
  int* c= nullptr;
 
  functionTemplate(0);   
  functionTemplate(NULL);
  functionTemplate(nullptr);  
}