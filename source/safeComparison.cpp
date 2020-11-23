// safeComparison.cpp

#include <iostream>
#include <utility>

int main() {

    std::cout << std::endl;

    std::cout << std::boolalpha;

    int x = -3;
    unsigned int y = 7;

    std::cout << "3 == 7:  " << std::cmp_equal(x, y) << std::endl;
    std::cout << "3 != 7:  " << std::cmp_not_equal(x, y) << std::endl;
    std::cout << "-3 < 7:  " << std::cmp_less(x, y) << std::endl;
    std::cout << "-3 <= 7: " << std::cmp_less_equal(x, y) << std::endl;
    std::cout << "-3 > 7:  " << std::cmp_greater(x, y) << std::endl;
    std::cout << "-3 => 7: " << std::cmp_greater_equal(x, y) << std::endl;
    
    std::cout << std::endl;
   
}