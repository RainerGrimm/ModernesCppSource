// traitsError.cpp

#include <iostream>
#include <typeinfo>

template <typename T, typename T2> // primary template
struct ReturnType;       

template <>  // full specialization for double, double
struct ReturnType <double, double> {
    typedef double Type;
};

template <> //  full specialization for double, bool
struct ReturnType <double, bool> {
    typedef double Type;
};

template <> // full specialization for bool, double
struct ReturnType <bool, double> {
    typedef double Type;
};

template <> // full specialization for bool, bool
struct ReturnType <bool, bool> {
    typedef int Type;
};

template <typename T, typename T2>  
typename ReturnType<T, T2>::Type sum(T t, T2 t2) {
    return t + t2;
}

int main() {

    std::cout << '\n';

    std::cout << "typeid(sum(5.5f, 5.5)).name(): " << typeid(sum(5.5f, 5.5)).name() << '\n';

    std::cout << '\n';

}