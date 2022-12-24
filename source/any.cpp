// any.cpp

#include <iostream>
#include <string>
#include <vector>
#include <any>

struct MyClass{};

int main(){
    
    std::cout << std::boolalpha;
    
    std::vector<std::any> anyVec{true,2017,std::string("test"),3.14,MyClass()};
    std::cout << "std::any_cast<bool>anyVec[0]: " << std::any_cast<bool>(anyVec[0]); // true
    int myInt= std::any_cast<int>(anyVec[1]);                                        
    std::cout << "myInt: " << myInt << std::endl;                                    // 2017
    
    std::cout << std::endl;
    std::cout << "anyVec[0].type().name(): " << anyVec[0].type().name();             // b
    std::cout << "anyVec[1].type().name(): " << anyVec[1].type().name();             // i
    
}
