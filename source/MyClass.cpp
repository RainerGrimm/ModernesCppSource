// MyClass.cpp

#include "MyClass.h"

template <typename T>
std::string MyClass<T>::getType() const {
    return typeid(T).name();
}

template class MyClass<int>; 