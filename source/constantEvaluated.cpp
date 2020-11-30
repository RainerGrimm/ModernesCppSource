// constantEvaluted.cpp

#include <type_traits>
#include <cmath>
#include <iostream>
 
constexpr double power(double b, int x) {
    if (std::is_constant_evaluated() && !(b == 0.0 && x < 0)) {
        
        if (x == 0)
            return 1.0;
        double r = 1.0, p = x > 0 ? b : 1.0 / b;
        auto u = unsigned(x > 0 ? x : -x);
        while (u != 0) {
            if (u & 1) r *= p;
            u /= 2;
            p *= p;
        }
        return r;
    } 
    else {
        return std::pow(b, double(x));
    }
}
 
int main() {
    
    std::cout << std::endl;
    
    constexpr double kilo1 = power(10.0, 3);
    std::cout << "kilo1: " << kilo1 << std::endl;
    
    int n = 3;
    double kilo2 = power(10.0, n);
    std::cout << "kilo2: " << kilo2 << std::endl;
    
    std::cout << std::endl;
    
}