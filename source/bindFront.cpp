// bindFront.cpp

#include <functional>
#include <iostream>

int plusFunction(int a, int b) {
    return a + b;
}

auto plusLambda = [](int a, int b) {
    return a + b;
};

int main() {
    
    std::cout << '\n';
    
    auto twoThousandPlus1 = std::bind_front(plusFunction, 2000);
    std::cout << "twoThousandPlus1(20): " << twoThousandPlus1(20) << '\n';
    
    auto twoThousandPlus2 = std::bind_front(plusLambda, 2000);
    std::cout << "twoThousandPlus2(20): " << twoThousandPlus2(20) << '\n';
    
    auto twoThousandPlus3 = std::bind_front(std::plus<int>(), 2000);
    std::cout << "twoThousandPlus3(20): " << twoThousandPlus3(20) << '\n';
    
    std::cout << "\n\n";
    
    using namespace std::placeholders;
    
    auto twoThousandPlus4 = std::bind(plusFunction, 2000, _1);
    std::cout << "twoThousandPlus4(20): " << twoThousandPlus4(20) << '\n';
    
    auto twoThousandPlus5 =  [](int b) { return plusLambda(2000, b); };
    std::cout << "twoThousandPlus5(20): " << twoThousandPlus5(20) << '\n';
       
    std::cout << '\n';
    
}
