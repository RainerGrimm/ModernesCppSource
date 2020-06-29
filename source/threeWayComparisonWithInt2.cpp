// threeWayComparisonWithInt2.cpp

#include <compare>
#include <iostream>

class MyInt {
 public:
    constexpr explicit MyInt(int val): value{val} { }    // (1)
    
    auto operator<=>(const MyInt& rhs) const = default;  // (2)
    
    constexpr auto operator<=>(const int& rhs) const {   // (3)
        return value <=> rhs;
    }
    
 private: 
    int value;
};


int main() {
    
    std::cout << std::boolalpha << std::endl;
    
    constexpr MyInt myInt2011(2011);
    constexpr MyInt myInt2014(2014);
    
    std::cout << "myInt2011 < myInt2014: " << (myInt2011 < myInt2014) << std::endl; // (2)

    std::cout << "myInt2011 < 2014: " << (myInt2011 < 2014) << std::endl;           // (3)
    
    std::cout << "myInt2011 < 2014.5: " << (myInt2011 < 2014.5) << std::endl;       // (3)
    
    std::cout << "myInt2011 < true: " << (myInt2011 < true) << std::endl;           // (3)
              
    std::cout << std::endl;
              
}
