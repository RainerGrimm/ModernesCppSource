// mainMyClass.cpp

#include "MyClass.h"
#include <iostream>


int main() {

    std::cout << '\n'; 

    MyClass myClass(5);
    std::cout << "myClass.getType(): " << myClass.getType() << '\n';

    /*
    MyClass myClass2(5.5);
    std::cout << "myClass2.getType(): " << myClass2.getType() << '\n';
    */

    std::cout << '\n';

}