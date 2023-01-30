// needRegularType.cpp 

#include <concepts>

template <std::regular T>
class MyClass{};
 
int main() {

    MyClass<int> myClass1;
    MyClass<int&> myClass2;
    
}