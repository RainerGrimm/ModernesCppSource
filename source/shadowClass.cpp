// shadowClass.cpp

#include <iostream>
#include <string>

struct Base{
    void shadow(std::string){                           // 2
        std::cout << "Base::shadow" << std::endl;       
    }
};

struct Derived: Base{
    using Base::shadow;
    void shadow(int){                                   // 3
        std::cout << "Derived::shadow" << std::endl;    
    }
};

int main(){
    
    std::cout << std::endl;
    
    Derived derived;
    
    derived.shadow(std::string{});                      // 1
    derived.shadow(int{});                              
    
    std::cout << std::endl;
    
}
