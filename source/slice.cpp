// slice.cpp

#include <iostream>
#include <typeinfo>

struct Base { };
 
struct Derived : Base { };

void displayTypeinfo(const Base& b) {
    std::cout << typeid(b).name() << '\n'; 
}

void needB(Base b) {
    displayTypeinfo(b);
};
 
int main() {

    Derived d;
  
    Base b = d;          
    displayTypeinfo(b);      
  
    Base b2(d);        
    displayTypeinfo(b2);     
  
    needB(d);                

}
