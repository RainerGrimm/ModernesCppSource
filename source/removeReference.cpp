// removeReference.cpp

#include <iostream>
#include <utility>

template<typename T, typename U>                 
struct isSame {
    static constexpr bool value = false;
};
 
template<typename T>                             
struct isSame<T, T> {
    static constexpr bool value = true;
}; 

template<typename T>                // (1)
struct removeReference { 
    using type = T;
};

template<typename T>               // (2)
struct removeReference<T&> {
    using type = T;
};

template<typename T>               // (3)
struct removeReference<T&&> {
    using type = T;
};

int main() {

    std::cout << '\n';

    std::cout << std::boolalpha;
                                    // (4)                
    std::cout << "isSame<int, removeReference<int>::type>::value: " << 
                  isSame<int, removeReference<int>::type>::value << '\n';

    std::cout << "isSame<int, removeReference<int&>::type>::value: " << 
                  isSame<int, removeReference<int&>::type>::value << '\n';

    std::cout << "isSame<int, removeReference<int&&>::type>::value: " << 
                  isSame<int, removeReference<int&&>::type>::value << '\n';


                                  // (5)

    int a(2011);
    int& b(a);   
    std::cout << "isSame<int, removeReference<decltype(a)>::type>::value: " << 
                  isSame<int, removeReference<decltype(a)>::type>::value << '\n';

    std::cout << "isSame<int, removeReference<decltype(b)>::type>::value: " << 
                  isSame<int, removeReference<decltype(b)>::type>::value << '\n';

    std::cout << "isSame<int, removeReference<decltype(std::move(a))>::type>::value: " << 
                  isSame<int, removeReference<decltype(std::move(a))>::type>::value << '\n';

    std::cout << '\n';

}