// decay.cpp

void decay(int*, void(*)(int), int, int ) { }      // (5)

void func(int){}                                   // (2)

int main() {

    int intArray[5]{1, 2, 3, 4, 5};                // (1)
    const int myInt{5};                            // (3)
    const int& myIntRef = myInt;                   // (4)

    decay(intArray, func, myInt, myIntRef);       

}