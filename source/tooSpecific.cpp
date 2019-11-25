// tooSpecific.cpp

#include <iostream>

void needInt(int i){
    std::cout << "int: " << i << std::endl;
}

int main(){
	
    std::cout << std::boolalpha << std::endl;
	
    double d{1.234};                             // (1)
    std::cout << "double: " << d << std::endl;
    needInt(d);                                  // (2)            
    
    std::cout << std::endl;
    
    bool b{true};                                // (3)
    std::cout << "bool: " << b << std::endl;
    needInt(b);                                  // (4)
	
    std::cout << std::endl;
	
}

