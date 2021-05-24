// arrayAssignment.cpp

#include <algorithm>
#include <cstddef>                     
#include <iostream>
#include <string>
#include <concepts>

template <typename T, std::size_t N>   
class Array{

 public:
    template <typename T2>
    Array<T, N>& operator = (const Array<T2, N>& arr) requires std::convertible_to<T2, T>;
    template<typename, std::size_t> friend class Array;
    int getSize() const;
 private:
    T elem[N];
    
};

template <typename T, std::size_t N> 
int Array<T, N>::getSize() const { return N; }

template<typename T, std::size_t N>
template<typename T2>
Array<T, N>& Array<T, N>::operator = (const Array<T2, N>& arr) requires std::convertible_to<T2, T> {
    std::copy(std::begin(arr.elem), std::end(arr.elem), std::begin(elem));
    return *this;
}

int main() {

    std::cout << '\n';

    Array<float, 5> floatArr;  
    Array<float, 5> floatArr2;
    floatArr.getSize();
    
    floatArr2 = floatArr;             // (1)
     
    
    Array<double, 5> doubleArr;       
    doubleArr = floatArr;             // (2)

    Array<std::string, 5> strArr;
    // doubleArr = strArr;            // (3)
    
}