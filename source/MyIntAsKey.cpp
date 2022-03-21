// MyIntAsKey.cpp

#include <iostream>
#include <unordered_map>

struct MyInt{
    explicit MyInt(int v):val(v){}
    int val;
};

int main(){

    std::cout << '\n';

    std::unordered_map<MyInt, int> myMap{ {MyInt(-2), -2}, {MyInt(-1), -1}, 
                                          {MyInt(0), 0}, {MyInt(1), 1} };

    std::cout << "\n\n";

}