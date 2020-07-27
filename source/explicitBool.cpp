// explicitBool.cpp

#include <iostream>
#include <string>
#include <type_traits>

struct Implicit {
    template <typename T>
    Implicit(T t) {
        std::cout << t << std::endl;
    }
};

struct Explicit {
    template <typename T>
    explicit Explicit(T t) {
        std::cout << t << std::endl;
    }
};

int main() {
    
    std::cout << std::endl;
    
    Implicit imp1 = "implicit";
    Implicit imp2("explicit");
    Implicit imp3 = 1998;
    Implicit imp4(1998);
    
    std::cout << std::endl;
    
    // Explicit exp1 = "implicit";
    Explicit exp2{"explicit"};
    // Explicit exp3 = 2011;
    Explicit exp4{2011};    
    
    std::cout << std::endl;  

}    

