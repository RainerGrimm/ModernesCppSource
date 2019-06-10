// overUnderflowStdArray.cpp

#include <array>
#include <iostream>

int main(){
    
    std::array<int, 1> a;
    int n{};

    while (true){
        if (!(n % 100)){
            std::cout << "a[" << n << "] = " << a[n] << 
                       ", a[" << -n << "] = " << a[-n] << "\n";
        }
        a[n] = n;
        a[-n] = -n;
        ++n;
    }
    
}
