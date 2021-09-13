// foldVariations.cpp

#include <iostream>

template<typename... Args>
auto diffL1(Args const&... args) {
    return (... - args);
}

template<typename... Args>
auto diffR1(Args const&... args) {
    return (args - ...);
}

template<typename Init, typename... Args>
auto diffL(Init init, Args const&... args) {
    return (init - ... - args);
}

template<typename Init, typename... Args>
auto diffR(Init init, Args const&... args) {
    return (args - ... - init);
}

int main() {

    std::cout << '\n';

    std::cout << "diffL1(1, 2, 3): " << diffL1(1, 2, 3) << '\n';       // (1 - 2) - 3
    std::cout << "diffR1(1, 2, 3): " << diffR1(1, 2, 3) << '\n';       // 1 - (2 - 3)
    std::cout << "diffL(10, 1, 2, 3): " << diffL(10, 1, 2, 3) << '\n'; // ((10 - 1) - 2) - 3
    std::cout << "diffR(10, 1, 2, 3): " << diffR(10, 1, 2, 3) << '\n'; // 1 - (2 - (3 - 10))

    std::cout << '\n';

}