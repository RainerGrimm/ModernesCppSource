// gslCheck.cpp

#include <iostream>

void f(int* p, int count) {
}

void f2(int* p) {
    int x = *p;
}

int main() {

    // Break of type safety
    // use of a c-cast
    double d = 2;
    auto p = (long*)&d;
    auto q = (long long*)&d;

    // Break of bounds safety
    // array to pointer decay

    int myArray[100];
    f(myArray, 100);
    // Break of Lifetime Safety
    // a is a nullptr
    int* a = new int;
    delete a;
    f2(a);

}