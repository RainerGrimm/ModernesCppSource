// inheritance.cpp

#include <iostream>

class Base{
public:
    void func(){                    // (1)
        std::cout << "func" << std::endl;
    }
};

class Derived: public Base{
public:
    void callBase(){
        func();                      // (2)
    }
};

int main(){

    std::cout << std::endl;

    Derived derived;
    derived.callBase();              

    std::cout << std::endl;

}
