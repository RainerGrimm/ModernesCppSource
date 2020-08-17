// uniqueAddress.cpp

#include <iostream>
 
struct Empty {}; 
 
struct NoUniqueAddress {
    int d{};
    Empty e{};
};
 
struct UniqueAddress {
    int d{};
    [[no_unique_address]] Empty e{};                                     // (1)
};
 
int main() {

    std::cout << std::endl;
    
    std::cout << std::boolalpha;

    std::cout << "sizeof(int) == sizeof(NoUniqueAddress): "              // (2)
              << (sizeof(int) == sizeof(NoUniqueAddress)) << std::endl;
 
    std::cout << "sizeof(int) == sizeof(UniqueAddress): "                // (3)
              << (sizeof(int) == sizeof(UniqueAddress)) << std::endl;
    
    std::cout << std::endl;
    
    NoUniqueAddress NoUnique;
    
    std::cout << "&NoUnique.d: " <<  &NoUnique.d << std::endl;           // (4)
    std::cout << "&NoUnique.e: " <<  &NoUnique.e << std::endl;           // (4)
    
    std::cout << std::endl;
    
    UniqueAddress unique;
    
    std::cout << "&unique.d: " <<  &unique.d << std::endl;               // (5)
    std::cout << "&unique.e: " <<  &unique.e << std::endl;               // (5)
    
    std::cout << std::endl;

}
