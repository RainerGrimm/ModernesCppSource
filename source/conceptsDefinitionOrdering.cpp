// conceptsDefinitionOrdering.cpp

#include <concepts>
#include <iostream>
#include <unordered_set>

template<typename T>
concept Equal =
    requires(T a, T b) {
        { a == b } -> std::convertible_to<bool>;
        { a != b } -> std::convertible_to<bool>;
    };


template <typename T>
concept Ordering =
    Equal<T> &&
    requires(T a, T b) {
        { a <= b } -> std::convertible_to<bool>;
        { a < b } -> std::convertible_to<bool>;
        { a > b } -> std::convertible_to<bool>;
        { a >= b } -> std::convertible_to<bool>;
    };

template <Equal T>
bool areEqual(T a, T b) {
    return a == b;
}

template <Ordering T>
T getSmaller(T a, T b) {
    return (a < b) ? a : b;
}
    
int main() {
  
    std::cout << std::boolalpha << std::endl;
  
    std::cout << "areEqual(1, 5): " << areEqual(1, 5) << std::endl;
  
    std::cout << "getSmaller(1, 5): " << getSmaller(1, 5) << std::endl;
  
    std::unordered_set<int> firSet{1, 2, 3, 4, 5};
    std::unordered_set<int> secSet{5, 4, 3, 2, 1};
  
    std::cout << "areEqual(firSet, secSet): " << areEqual(firSet, secSet) << std::endl;
  
    // auto smallerSet= getSmaller(firSet, secSet);
  
    std::cout << std::endl;
  
}
