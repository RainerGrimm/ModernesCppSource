// variadicTemplatesFoldExpression.cpp

#include <iostream>

bool allVar() {                                              // (1)
    return true;
}

template<typename T, typename ...Ts>
bool allVar(T t, Ts ... ts) {
    return t && allVar(ts...);
}

template<typename... Args>
bool all(Args... args) { return (... && args); }

int main() {

    std::cout << std::boolalpha;

    std::cout << '\n';

    std::cout << "allVar(): " << allVar() << '\n';
    std::cout << "all(): " << all() << '\n';

    std::cout << "allVar(true): " << allVar(true) << '\n';
    std::cout << "all(true): " << all(true) << '\n';

    std::cout << "allVar(true, true, true, false): " 
              << allVar(true, true, true, false) << '\n';
    std::cout << "all(true, true, true, false): " 
              << all(true, true, true, false) << '\n';

    std::cout << '\n';

}