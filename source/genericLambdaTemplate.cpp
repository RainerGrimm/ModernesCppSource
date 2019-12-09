// genericLambdaTemplate.cpp

#include <iostream>
#include <string>

auto addLambda = [](auto fir, auto sec){ return fir + sec; };   // (1)

template <typename T, typename T2>                              // (2)
auto addTemplate(T fir, T2 sec){ return fir + sec; }

int main(){

    std::cout << std::boolalpha << std::endl;

    std::cout << addLambda(1, 5) << " " << addTemplate(1, 5) << std::endl;
    std::cout << addLambda(true, 5) << " " << addTemplate(true, 5) << std::endl;
    std::cout << addLambda(1, 5.5) << " " << addTemplate(1, 5.5) << std::endl;
    
    const std::string fir{"ge"};
    const std::string sec{"neric"};
    std::cout << addLambda(fir, sec) << " " << addTemplate(fir, sec) << std::endl;

    std::cout << std::endl;

}
