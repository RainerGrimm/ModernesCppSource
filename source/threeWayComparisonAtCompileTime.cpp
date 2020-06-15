// threeWayComparisonAtCompileTime.cpp

#include <compare>
#include <iostream>


struct MyDouble {
    double value;
    explicit constexpr MyDouble(double val): value{val} { }
    auto operator<=>(const MyDouble&) const = default;    
};

template <typename T>
constexpr bool isLessThan(const T& lhs, const T& rhs) {
    return lhs < rhs;
}

int main() {
    
    std::cout << std::boolalpha << std::endl;

              
    constexpr MyDouble myDouble1(2011);
    constexpr MyDouble myDouble2(2014);
    
    constexpr bool res = isLessThan(myDouble1, myDouble2);
    
    std::cout << "isLessThan(myDouble1, myDouble2): "
              << res << std::endl;          
              
    std::cout << std::endl;
              
}
