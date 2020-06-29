// threeWayComparisonWithInt5.cpp

#include <compare>
#include <iostream>

class MyInt {
 public:
    constexpr explicit MyInt(int val): value{val} { }
    bool operator == (const MyInt& rhs) const {                  
        std::cout << "==  " << std::endl;
        return value == rhs.value;
    }
    bool operator < (const MyInt& rhs) const {                  
        std::cout << "<  " << std::endl;
        return value < rhs.value;
    }
    
    auto operator<=>(const MyInt& rhs) const = default;
    
 private:
     int value;
};

int main() {
    
    MyInt myInt2011(2011);
    MyInt myInt2014(2014);
    
    myInt2011 == myInt2014;
    myInt2011 != myInt2014;
    myInt2011 < myInt2014;
    myInt2011 <= myInt2014;
    myInt2011 > myInt2014;
    myInt2011 >= myInt2014;
    
}
