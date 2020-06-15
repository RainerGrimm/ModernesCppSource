// comparisonOperator.cpp

#include <iostream>

struct MyInt {
    int value;
    explicit MyInt(int val): value{val} { }
    bool operator < (const MyInt& rhs) const {                  
        return value < rhs.value;
    }
};

template <typename T>
constexpr bool isLessThan(const T& lhs, const T& rhs) {
    return lhs < rhs;
}

int main() {

    std::cout << std::boolalpha << std::endl;

    MyInt myInt2011(2011);
    MyInt myInt2014(2014);

    std::cout << "isLessThan(myInt2011, myInt2014): "
              << isLessThan(myInt2011, myInt2014) << std::endl;

   std::cout << std::endl;

}
