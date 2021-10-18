// typeinfo.cpp

#include <iostream>
#include <typeinfo>
 
int main() {
	
    std::cout << '\n';
 
    std::cout << "typeid(5.5 + 5.5).name(): " << typeid(5.5 + 5.5).name() << '\n';
	std::cout << "typeid(5.5 + true).name(): " << typeid(5.5 + true).name() << '\n';
	std::cout << "typeid(true + 5.5).name(): " << typeid(true + 5.5).name() << '\n';
    std::cout << "typeid(true + false).name(): " << typeid(true + false).name() << '\n';

    std::cout << '\n';
    
}