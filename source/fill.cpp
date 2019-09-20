// fill.cpp

#include <chrono>
#include <cstring>
#include <iostream>
#include <type_traits>

namespace my {

template <typename I, typename T, bool b>
void fill_impl(I first, I last, const T& val, const std::integral_constant<bool, b>&)
{
    while (first != last) {
        *first = val;
        ++first;
    }
}

template <typename T>
void fill_impl(T* first, T* last, const T& val, const std::true_type&)
{
    std::memset(first, val, last - first);
}

template <class I, class T>
inline void fill(I first, I last, const T& val)
{
    // typedef std::integral_constant<bool,std::has_trivial_copy_assign<T> ::value && (sizeof(T) == 1)> boolType;
    typedef std::integral_constant<bool, std::is_trivially_copy_assignable<T>::value && (sizeof(T) == 1)> boolType;
    fill_impl(first, last, val, boolType());
}
}

const int arraySize = 100000000;
char charArray1[arraySize] = {
    0,
};
char charArray2[arraySize] = {
    0,
};

int main()
{

    std::cout << std::endl;

    auto begin = std::chrono::system_clock::now();
    my::fill(charArray1, charArray1 + arraySize, 1);
    auto last = std::chrono::system_clock::now() - begin;
    std::cout << "charArray1: " << std::chrono::duration<double>(last).count() << " seconds" << std::endl;

    begin = std::chrono::system_clock::now();
    my::fill(charArray2, charArray2 + arraySize, static_cast<char>(1));
    last = std::chrono::system_clock::now() - begin;
    std::cout << "charArray2: " << std::chrono::duration<double>(last).count() << " seconds" << std::endl;

    std::cout << std::endl;
}
