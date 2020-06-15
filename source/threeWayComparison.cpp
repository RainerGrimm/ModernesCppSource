// threeWayComparison.cpp

#include <compare>
#include <iostream>

struct MyInt {
    int value;
    explicit MyInt(int val): value{val} { }
    auto operator<=>(const MyInt& rhs) const {          
        return value <=> rhs.value;
    }
};

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
    
    MyInt myInt1(2011);
    MyInt myInt2(2014);
    
    std::cout << "isLessThan(myInt1, myInt2): "
              << isLessThan(myInt1, myInt2) << std::endl;
              
    MyDouble myDouble1(2011);
    MyDouble myDouble2(2014);
    
    std::cout << "isLessThan(myDouble1, myDouble2): "
              << isLessThan(myDouble1, myDouble2) << std::endl;          
              
    std::cout << std::endl;
              
}
