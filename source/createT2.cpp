// createT2.cpp

#include <utility>

struct MyType{
    MyType(int, double, bool){};
};

template <typename T, typename ... Args>
T createT(Args&& ... args){
    return T(std::forward<Args>(args) ... );
}
    
int main(){
    
    int lvalue{2020};
    
    int uniqZero = createT<int>();                       // (1)
    auto uniqEleven = createT<int>(2011);                // (2)
    auto uniqTwenty = createT<int>(lvalue);              // (3)
    auto uniqType = createT<MyType>(lvalue, 3.14, true); // (4)
    
}
