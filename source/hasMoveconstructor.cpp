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

struct NoCopySemantics{ 

    NoCopySemantics() = default;
    NoCopySemantics(const NoCopySemantics&) = delete;
    NoCopySemantics& operator = (const NoCopySemantics&) = delete;
    NoCopySemantics(NoCopySemantics&&) = default;
    NoCopySemantics& operator = (NoCopySemantics&&) = default;
    ~NoCopySemantics() = default;
};

struct MyData: public NoCopySemantics{};



int main(){

    std::cout << '\n';
                            
    static_assert(std::is_move_constructible<MyData>::value, "BigSix not supported");  // (4)
    static_assert(std::is_copy_constructible<MyData>::value, "BigSix not supported"); 

    std::cout << '\n';

};