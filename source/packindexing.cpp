// packIndexing.cpp

#include <iostream>
#include <string>

template <typename... T>
constexpr auto first_plus_last(T... values) -> T...[0] {
    return T...[0](values...[0] + values...[sizeof...(values)-1]);
}

int main() {

    std::cout << '\n';

    using namespace std::string_literals;

    std::string hello = first_plus_last("Hello"s, "world"s, "goodbye"s, "World"s); 
    std::cout << "hello: " << hello << '\n';


    constexpr int sum = first_plus_last(1, 2, 10);
    std::cout << "sum: " << sum << '\n';

    std::cout << '\n';
  
}