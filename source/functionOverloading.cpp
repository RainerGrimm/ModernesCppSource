// functionOverloading.cpp

#include <iostream>  
  
void print(int) { 
    std::cout << "int" << std::endl; 
} 

void print(double) { 
    std::cout << "double" << std::endl; 
} 

void print(const char*) { 
    std::cout << "const char* " << std::endl; 
} 

void print(int, double, const char*) { 
    std::cout << "int, double, const char* " << std::endl; 
} 

  
int main() { 
 
    std::cout << std::endl;   

    print(10); 
    print(10.10); 
    print("ten"); 
    print(10, 10.10, "ten");

    std::cout << std::endl;

}
