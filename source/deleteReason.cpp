// deleteReason.cpp

#include <iostream>


void func(double){}

template <typename T>
void func(T) = delete("Only for double");

int main(){

    std::cout << '\n';

    func(3.14);
    func(3.14f);
  
    std::cout << '\n';

}
