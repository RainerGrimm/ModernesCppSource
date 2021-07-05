// isSame.cpp

#include <iostream>

template<typename T, typename U>                 // (1)
struct isSame {
    static constexpr bool value = false;
};
 
template<typename T>                             // (2)
struct isSame<T, T> {
    static constexpr bool value = true;
}; 

int main() {

    std::cout << '\n';                          

    std::cout << std::boolalpha;
                                                // (3)
    std::cout << "isSame<int, int>::value: " << isSame<int, int>::value << '\n';
    std::cout << "isSame<int, int&>::value: " << isSame<int, int&>::value << '\n';
  
                                                
    int a(2011);
    int& b(a);                                  // (4)
    std::cout << "isSame<decltype(a), decltype(b)>::value " << 
                  isSame<decltype(a), decltype(b)>::value << '\n';

    std::cout << '\n';

}