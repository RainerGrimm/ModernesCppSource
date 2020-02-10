// requirementsCheckSFINAE.cpp

#include <type_traits>

template<typename T,
         typename std::enable_if<std::is_integral<T>::value, T>:: type = 0>
T moduloOf(T t) {
    return t % 5;
}

int main() {

    auto res = moduloOf(5.5);

}
