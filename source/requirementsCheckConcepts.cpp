// requirementsCheckConcepts.cpp

#include <concepts>

std::integral auto moduloOf(std::integral auto t) {
    return t % 5;
}

int main() {

    auto res = moduloOf(5.5);

}
