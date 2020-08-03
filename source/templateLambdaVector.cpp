// templateLambdaVector.cpp

#include <concepts>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

auto lambdaGeneric = [](const auto& container) { return container.size(); };  
auto lambdaVector = []<typename T>(const std::vector<T>& vec) { return vec.size(); };
auto lambdaVectorIntegral = []<std::integral T>(const std::vector<T>& vec) { return vec.size(); };

int main() {

    
    std::cout << std::endl;
    
    std::deque deq{1, 2, 3};
    std::vector vecDouble{1.1, 2.2, 3.3, 4.4};
    std::vector vecInt{1, 2, 3, 4, 5};
  
    std::cout << "lambdaGeneric(deq): " << lambdaGeneric(deq) << std::endl;
    // std::cout << "lambdaVector(deq): " << lambdaVector(deq) << std::endl;                  ERROR
    // std::cout << "lambdaVectorIntegral(deq): " << lambdaVectorIntegral(deq) << std::endl;  ERROR

    std::cout << std::endl;
    
    std::cout << "lambdaGeneric(vecDouble): " << lambdaGeneric(vecDouble) << std::endl;
    std::cout << "lambdaVector(vecDouble): " << lambdaVector(vecDouble) << std::endl;
    // std::cout << "lambdaVectorIntegral(vecDouble): " << lambdaVectorIntegral(vecDouble) << std::endl;
    
    std::cout << std::endl;
     
    std::cout << "lambdaGeneric(vecInt): " << lambdaGeneric(vecInt) << std::endl;
    std::cout << "lambdaVector(vecInt): " << lambdaVector(vecInt) << std::endl;
    std::cout << "lambdaVectorIntegral(vecInt): " << lambdaVectorIntegral(vecInt) << std::endl;
    
    std::cout << std::endl;
    
}

