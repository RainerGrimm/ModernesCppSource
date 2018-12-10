// genericArray.cpp

#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
class Array{
public:
    Array()= default;
    std::size_t getSize() const{
        return N;
    }
private:
  T elem[N];
};

int main(){

    Array<int, 100> arr1;
    std::cout << "arr1.getSize(): " << arr1.getSize() << std::endl;

    Array<int, 200> arr2;
    std::cout << "arr2.getSize(): " << arr2.getSize() << std::endl;
    
}
