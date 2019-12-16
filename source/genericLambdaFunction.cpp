// genericLambdaFunction.cpp

#include <iostream>
#include <string>

auto addLambda = [](auto fir, auto sec){ return fir + sec; }; // (1)

auto addFunction(auto fir, auto sec){ return fir + sec; }     // (2)

int main(){

    std::cout << std::boolalpha << std::endl;

    std::cout << addLambda(1, 5) << " " << addFunction(1, 5) << std::endl;
    std::cout << addLambda(true, 5) << " " << addFunction(true, 5) << std::endl;
    std::cout << addLambda(1, 5.5) << " " << addFunction(1, 5.5) << std::endl;
    
    const std::string fir{"ge"};
    const std::string sec{"neric"};
    std::cout << addLambda(fir, sec) << " " << addFunction(fir, sec) << std::endl;

    std::cout << std::endl;

}
