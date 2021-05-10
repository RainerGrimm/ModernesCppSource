 // automaticReturnTypeDeduction.cpp

#include <type_traits>

template <typename T1, typename T2>      // (1)
typename std::conditional<(sizeof(T1) > sizeof(T2)), T1, T2>::type max1(T1 lhs,T2 rhs) {
    return (lhs > rhs)? lhs : rhs;
}

template <typename T1, typename T2>      // (2)
typename std::common_type<T1, T2>::type max2(T1 lhs,T2 rhs) {
    return (lhs > rhs)? lhs : rhs;
}

template <typename T1, typename T2>     // (3)
auto max3(T1 lhs,T2 rhs) {
    return (lhs > rhs)? lhs : rhs;
}

int main() {
  
    max1(10.5f, 5.5);                  
    max2(10.5f, 5.5);                  
    max3(10.5f, 5.5);                  
  
}
