// makeUnique.cpp

#include <memory>

struct MyType{
    MyType(int, double, bool){};
};

int main(){
    
    int lvalue{2020};
    
    std::unique_ptr<int> uniqZero = std::make_unique<int>();      // (1)
    auto uniqEleven = std::make_unique<int>(2011);                // (2)
    auto uniqTwenty = std::make_unique<int>(lvalue);              // (3)
    auto uniqType = std::make_unique<MyType>(lvalue, 3.14, true); // (4)
    
}
