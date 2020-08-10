// lambdaCaptureThis.cpp

#include <iostream>
#include <string>

struct Lambda {
    auto foo() const {
        return [=] { std::cout << s << std::endl; };      
    }
    std::string s = "lambda";
     ~Lambda() {
        std::cout << "Goodbye" << std::endl;
    }
};

auto makeLambda() {                                               
    Lambda lambda;
    return lambda.foo();
}                                                                                      


int main() {
    
    std::cout << std::endl;

    auto lam = makeLambda();                                
    lam();                                                                       
    
    std::cout << std::endl;
    
}
