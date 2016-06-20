// copyFallbackMove.cpp

#include <iostream>
#include <type_traits>
#include <utility>

template <typename T>
void swapMove(T& a, T& b){
    T tmp(std::move(a));
    a= std::move(b);
    b= std::move(tmp);
}

class MyInt{
public:
    MyInt(int i_):i(i_){}
    
    // copy semantic
    MyInt(const MyInt& myInt):i(myInt.getVal()){}
    MyInt& operator= (const MyInt& myInt){
        i= myInt.getVal();
        return *this;
    }
        
    int getVal() const {
        return i;
    }
private:
    int i;
};

int main(){
    
    std::cout << std::endl;
    MyInt myInt1(1);
    MyInt myInt2(2);
    
    std::cout << std::boolalpha;
    
    std::cout << "std::is_trivially_move_constructible<MyInt>::value " << std::is_trivially_move_constructible<MyInt>::value << std::endl;
    std::cout << "std::is_trivially_move_assignable<MyInt>::value " << std::is_trivially_move_assignable<MyInt>::value << std::endl;
    
    std::cout << "myInt1.getVal() :" << myInt1.getVal() << std::endl;
    std::cout << "myInt2.getVal() :" << myInt2.getVal() << std::endl;
    
    swapMove(myInt1,myInt2);
    std::cout << std::endl;
    
    std::cout << "myInt1.getVal() :" << myInt1.getVal() << std::endl;
    std::cout << "myInt2.getVal() :" << myInt2.getVal() << std::endl;
    
    std::cout << std::endl;
    
}

