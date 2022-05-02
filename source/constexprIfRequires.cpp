// constexprIfRequires.cpp

#include <concepts>
#include <iostream>

struct First {
    int count() const {
        return 2020;
    }
};

struct Second {
    int size() const {
        return 2021;
    }
};

template <typename T>
int getNumberOfElements(T t) {

    if constexpr (requires(T t){ { t.count() } -> std::convertible_to<int>; }) {
        return t.count();
    }
    if constexpr (requires(T t){ { t.size() } -> std::convertible_to<int>; }) {
        return t.size();
    }
    else return 42;

}

int main() {

    std::cout << '\n';
   
    First first;
    std::cout << "getNumberOfElements(first): "  << getNumberOfElements(first) << '\n';

    Second second;
    std::cout << "getNumberOfElements(second): "  << getNumberOfElements(second) << '\n';

    int third;
    std::cout << "getNumberOfElements(third): " << getNumberOfElements(third) << '\n';

    std::cout << '\n';

}