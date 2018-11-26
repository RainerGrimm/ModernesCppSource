// equalityComparable.cpp

#include <experimental/type_traits>                                                      // (1)
#include <iostream>

template<typename T>
using equal_comparable_t = decltype(std::declval<T&>() == std::declval<T&>());           // (2)

template<typename T>
struct isEqualityComparable: 
       std::experimental::is_detected<equal_comparable_t, T>{};                          // (3)

struct EqualityComparable { };                                                           // (4)
bool operator == (EqualityComparable const&, EqualityComparable const&) { return true; }

struct NotEqualityComparable { };                                                        // (5)
 
int main() {
    
    std::cout << std::boolalpha << std::endl;
    
    std::cout << "isEqualityComparable<EqualityComparable>::value: " << 
                  isEqualityComparable<EqualityComparable>::value << std::endl;
                  
    std::cout << "isEqualityComparable<NotEqualityComparable>::value: " << 
                  isEqualityComparable<NotEqualityComparable>::value << std::endl;
    
    std::cout << std::endl;
    
}
