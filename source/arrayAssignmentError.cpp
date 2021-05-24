// arrayAssignmentError.cpp

#include <cstddef>                     
#include <iostream>
#include <string>

template <typename T, std::size_t N>   
class Array{

 public:
    std::size_t getSize() const {
        return N;
    }

private:
    T elem[N];
};

int main() {

    std::cout << '\n';

    Array<float, 5> floatArr;  
    Array<float, 5> floatArr2;
    
    floatArr2 = floatArr;             // (1)
     
    
    Array<double, 5> doubleArr;       
    doubleArr = floatArr;             // (2)
    
    
}
