// static_assert26.cpp

#include <iostream>
#include <format>

template <typename T, auto Expected, unsigned long Size = sizeof(T)>
constexpr bool ensure_size() {
    static_assert(sizeof(T) == Expected, "Unexpected sizeof");
    return true;
}

struct S {
    int _{};
};

int main() {

    std::cout << std::boolalpha << "C++11\n";
    static_assert(ensure_size<S, 1>()); 

    std::cout << std::boolalpha << "C++26\n";
    static_assert(sizeof(S) == 1,
        std::format("Unexpected sizeof: expected 1, got {}", sizeof(S))); 

    std::cout << '\n';    

}

