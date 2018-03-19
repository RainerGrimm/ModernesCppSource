// overUnderflow.cpp

#include <cstddef>
#include <iostream>

int main(){
    
    int a[0];
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
