// swap.cpp

#include <algorithm>
#include <cstddef> 
#include <iostream>
#include <vector>

template <typename T>                                                // (3)
void swap(T& a, T& b) noexcept {
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

class BigArray{

public:
    BigArray(std::size_t sz): size(sz), data(new int[size]){}

    BigArray(const BigArray& other): size(other.size), data(new int[other.size]){
        std::cout << "Copy constructor" << std::endl;
        std::copy(other.data, other.data + size, data);
    }
    
    BigArray& operator=(const BigArray& other){                      // (1)
        std::cout << "Copy assignment" << std::endl;
        if (this != &other){
            delete [] data;
            data = nullptr;
			
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }
    
    ~BigArray(){
        delete[] data;
    }
private:
    std::size_t size;
    int* data;
};

int main(){

  std::cout << std::endl;

  BigArray bigArr1(2011);
  BigArray bigArr2(2017);
  swap(bigArr1, bigArr2);                                           // (3)

  std::cout << std::endl;

};

