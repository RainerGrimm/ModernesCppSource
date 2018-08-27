// mutable.cpp

#include <iostream>

struct Immutable{
    mutable int val{12};            // (1)
    void canNotModify() const {
        val = 13;
    }

};

int main(){
    
    std::cout << std::endl;
    
    const Immutable immu;
    std::cout << "val: " << immu.val << std::endl;
    immu.canNotModify();            // (2)
    std::cout << "val: " << immu.val << std::endl;
    
    std::cout << std::endl;
    
}