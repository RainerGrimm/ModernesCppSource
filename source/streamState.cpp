// streamState.cpp

#include <ios>
#include <iostream>

int main(){

    std::cout << std::boolalpha << std::endl;

    std::cout <<  "In failbit-state: " << std::cin.fail() << std::endl;
  
    std::cout << std::endl;
  
    int myInt;
    while (std::cin >> myInt){
        std::cout << "Output: " << myInt << std::endl; 
        std::cout <<  "In failbit-state: " << std::cin.fail() << std::endl;
        std::cout << std::endl;
    }
  
    std::cout <<  "In failbit-state: " << std::cin.fail() << std::endl;
    std::cin.clear();
    std::cout <<  "In failbit-state: " << std::cin.fail() << std::endl;

    std::cout << std::endl;

}
