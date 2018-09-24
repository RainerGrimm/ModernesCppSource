// narrowingConversion.cpp

#include <iostream>

void needInt(int i){
    std::cout << "int: " << i << std::endl;
}

int main(){
	
    std::cout << std::endl;
	
	double d{1.234};
	std::cout << "double: " << d << std::endl;
	
	needInt(d);
	
	std::cout << std::endl;
	
}

