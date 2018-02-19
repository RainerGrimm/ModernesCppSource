// sliceVirtuality.cpp

#include <iostream>
#include <string>

struct Base { 
    virtual std::string getName() const {        // (1)
        return "Base";       
    }
};
 
struct Derived : Base { 
    std::string getName() const override {       // (2)
        return "Derived";
    }
};
 
int main(){
    
    std::cout << std::endl;
    
    Base b;
    std::cout << "b.getName(): " << b.getName() << std::endl;       // (3)
    
    Derived d;
    std::cout << "d.getName(): " << d.getName() << std::endl;       // (4)
    
    Base b1 = d;
    std::cout << "b1.getName():  " << b1.getName() << std::endl;    // (5)
   
    Base& b2 = d;
    std::cout << "b2.getName():  " << b2.getName() << std::endl;    // (6)

    Base* b3 = new Derived;
    std::cout << "b3->getName(): " << b3->getName() << std::endl;   // (7)
    
    std::cout << std::endl;

}
