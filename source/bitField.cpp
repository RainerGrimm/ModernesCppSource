// bitField.cpp

#include <iostream>

struct Class11 {
    int i = 1;
    int j = 2;
    int k = 3;
    int l = 4;
    int m = 5;
    int n = 6;
};

struct BitField20 {
    int i : 3 = 1;
    int j : 4 = 2;
    int k : 5 = 3;
    int l : 6 = 4;
    int m : 7 = 5;
    int n : 7 = 6;
};

int main () {
    
    std::cout << std::endl;

    std::cout << "sizeof(Class11): " << sizeof(Class11) << std::endl;
    std::cout << "sizeof(BitField20): " << sizeof(BitField20) << std::endl;
    
    std::cout << std::endl;
    
}
