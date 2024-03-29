// powerHybrid.cpp

#include <iostream>

template<int n>
int Power(int m){
    return m * Power<n-1>(m);
}

template<>
int Power<0>(int m){
    return 1;
}

int main() {
    
    std::cout << '\n';

    std::cout << "Power<0>(10): " << Power<0>(20) << '\n';
    std::cout << "Power<1>(10): " << Power<1>(10) << '\n';
    std::cout << "Power<2>(10): " << Power<2>(10) << '\n';
    

    std::cout << '\n';

}