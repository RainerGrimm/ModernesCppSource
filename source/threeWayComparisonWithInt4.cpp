// threeWayComparisonWithInt4.cpp

#include <compare>
#include <iostream>

class MyInt {
 public:
    constexpr explicit MyInt(int val): value{val} { }
    
    auto operator<=>(const MyInt& rhs) const = default;  
    
    constexpr auto operator<=>(const int& rhs) const {
        return value <=> rhs;
    }
    
    constexpr friend MyInt operator+(const MyInt& a, const MyInt& b){
        return MyInt(a.value + b.value);
    }
    
    constexpr friend MyInt operator-(const MyInt& a,const MyInt& b){
        return MyInt(a.value - b.value);
    }
    
    constexpr friend MyInt operator*(const MyInt& a, const MyInt& b){
        return MyInt(a.value * b.value);
    }
    
    constexpr friend MyInt operator/(const MyInt& a, const MyInt& b){
        return MyInt(a.value / b.value);
    }
    
    friend std::ostream& operator<< (std::ostream &out, const MyInt& myInt){
        out << myInt.value;
        return out;
    }
    
 private: 
    int value;
};


int main() {
    
    std::cout << std::boolalpha << std::endl;
    
    constexpr MyInt myInt2011(2011);
    constexpr MyInt myInt2014(2014);
    
    std::cout << "myInt2011 < myInt2014: " << (myInt2011 < myInt2014) << std::endl;

    std::cout << "myInt2011 < 2014: " << (myInt2011 < 2014) << std::endl;
    
    std::cout << "myInt2011 < 2014.5: " << (myInt2011 < 2014.5) << std::endl;
    
    std::cout << "myInt2011 < true: " << (myInt2011 < true) << std::endl;
    
    constexpr MyInt res1 = (myInt2014 - myInt2011) * myInt2011;
    std::cout << "res1: " << res1 << std::endl;
    
    constexpr MyInt res2 = (myInt2014 - myInt2011) * 2011;
    std::cout << "res2: " << res2 << std::endl;
    
    constexpr MyInt res3 = (false + myInt2011 + 0.5)  / true;
    std::cout << "res3: " << res3 << std::endl;
    
              
    std::cout << std::endl;
              
}
