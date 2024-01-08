// equalityOperator.cpp

#include <iostream>
#include <tuple>
#include <unordered_set>

struct MyInt {
    int value;
    std::unordered_set<int> mySet;
    explicit MyInt(int val): value{val}, mySet{val} { }
    bool operator==(const MyInt& rhs) const {                 
        return std::tie(value, mySet) == std::tie(rhs.value, rhs.mySet);
    }
};

struct MyDouble {
    double value;
    std::unordered_set<double> mySet;
    explicit MyDouble(double val): value{val}, mySet{val} { }
    bool operator==(const MyDouble&) const = default;   
};

template <typename T>
constexpr bool areEqual(const T& lhs, const T& rhs) {

    return lhs == rhs;
}

template <typename T>
constexpr bool areNotEqual(const T& lhs, const T& rhs) {

    return lhs != rhs;
}

int main() {
    
    std::cout << std::boolalpha << '\n';
    
    MyInt myInt1(2011);
    MyInt myInt2(2014);
    
    std::cout << "areEqual(myInt1, myInt2): "
              << areEqual(myInt1, myInt2) << '\n';
    std::cout << "areNotEqual(myInt1, myInt2): "
              << areNotEqual(myInt1, myInt2) << '\n';

    std::cout << '\n';          
              
    MyDouble myDouble1(2011.0);
    MyDouble myDouble2(2014.0);
    
    std::cout << "areEqual(myDouble1, myDouble2): "
              << areEqual(myDouble1, myDouble2) << '\n';
    std::cout << "areNotEqual(myDouble1, myDouble2): "
              << areNotEqual(myDouble1, myDouble2) << '\n';           
              
    std::cout << '\n';
              
}