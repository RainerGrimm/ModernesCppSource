// myBool.cpp

#include <iostream>
#include <type_traits>
#include <typeinfo>

struct MyBool {
    template <typename T>
    explicit(!std::is_same<T, bool>::value) MyBool(T t) {
        std::cout << typeid(t).name() << std::endl;
    }
};

void needBool(MyBool b){ }

int main() {

    MyBool myBool1(true);
    MyBool myBool2 = false;
    
    needBool(myBool1);
    needBool(true);
    // needBool(5);
    // needBool("true");
    
}
