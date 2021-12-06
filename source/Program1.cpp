// Program1.cpp

#include <iostream>
struct Base
{
};
struct Derived : public Base
{
};
struct A
{
};
// Conversion that converts pointer-to-derived to pointer-to-base
// is better than the conversion of pointer-to-derived to pointer-to-void,
// https://en.cppreference.com/w/cpp/language/overload_resolution
void f(void *)
{
    std::cout << "f(void*)" << std::endl;
}
void f(const Base *)
{
    std::cout << "f(Base*)" << std::endl;
}
int main()
{
    Derived d;
    A a;
    f(&d);
    f(&a);
    return 0;
}