// gslCheckSuppress.cpp

#include <iostream>

void f(int* p, int count) {
}

int main() {

    int myArray[100];
    
    // Break of bounds safety
    [[gsl::suppress(bounds.3)]] {   // suppress warning
        f(myArray, 100);
    }

    f(myArray, 100);                // warning           

}