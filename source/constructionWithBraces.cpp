// constructionWihtBraces.cpp

#include <iostream>

class MyVector{
public:
    MyVector(int, int){
        std::cout << "MyVector(int, int)" << std::endl;
    }
    MyVector(std::initializer_list<int>){
        std::cout << "MyVector(std::initalizer_list<int>)" << std::endl;
    }
};

class MyVector1{
public:
    MyVector1(int, int){
        std::cout << "MyVector1(int, int)" << std::endl;
    }
};

class MyVector2{
public:
    MyVector2(int, int){
        std::cout << "MyVector(int, int)" << std::endl;
    }
};

int main(){
    
    std::cout << std::endl;
    
    MyVector(1, 2);                       // (1)
    MyVector{1, 2};                       // (2) 
    
    std::cout << std::endl;
    
    MyVector1{1, 2};                      // (3)
    
    std::cout << std::endl;
    
    MyVector2(1, 2);                      // (4)
    
    std::cout << std::endl;
    
}
