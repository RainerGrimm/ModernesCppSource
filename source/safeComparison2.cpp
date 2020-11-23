// safeComparison2.cpp

#include <iostream>
#include <utility>

int main() {

    double x = -3.5;
    unsigned int y = 7;

    std::cout << "-3.5 < 7:  " << std::cmp_less(x, y) << std::endl;

}

