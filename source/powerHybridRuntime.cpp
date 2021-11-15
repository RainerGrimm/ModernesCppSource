// powerHybridRuntime.cpp

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

    auto Power2of = Power<2>;

    for (int i = 0; i <= 20; ++i) {
        std::cout << "Power2of(" << i << ")= "
                  << Power2of(i)  << '\n';
     }

    std::cout << '\n';

}