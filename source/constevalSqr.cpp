// constevalSqr.cpp

#include <iostream>

consteval int sqr(int n) {
    return n * n;
}

int main() {
    
    std::cout << "sqr(5): " << sqr(5) << std::endl;
    
    const int a = 5;
    std::cout << "sqr(a): " << sqr(a) << std::endl;

    int b = 5;
    std::cout << "sqr(b): " << sqr(5) << std::endl;

}
