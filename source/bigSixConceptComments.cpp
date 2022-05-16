// bigSixConceptComments.cpp

#include <algorithm>
#include <iostream>
#include <type_traits>

template<typename T>
struct isBigSix: std::integral_constant<bool,
                                      std::is_default_constructible<T>::value &&
                                      std::is_copy_constructible<T>::value &&
                                      std::is_copy_assignable<T>::value &&
                                      std::is_move_constructible<T>::value &&
                                      std::is_move_assignable<T>::value &&
                                      std::is_destructible<T>::value>{};


template<typename T>
concept BigSix = isBigSix<T>::value;

template <BigSix T>                                   
void swap(T& a, T& b) noexcept {
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

struct MyData{                                        
    MyData() = default;
    MyData(const MyData& ) {
        std::cout << "copy constructor\n";
    }
    MyData& operator=(const MyData& m) {
        std::cout << "copy assignment operator\n";
        return *this;
    }

};

int main(){

    std::cout << '\n';

    MyData a, b;
    swap(a, b);       
    
    static_assert(BigSix<MyData>, "BigSix not supported");                             

    std::cout << '\n';

};