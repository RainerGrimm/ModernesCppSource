// lazyInstantiation.cpp

#include <cstddef> 

class Array1 { 
 public: 
    int getSize() const { 
      return 10; 
 } 
 private: 
    int elem[10]; 
};

template <typename T, std::size_t N> 
class Array2 { 
 public: 
    std::size_t getSize() const {
        return N;
    }
  private: 
     T elem[N]; 
}; 


int main() {

    Array1 arr;
    
    Array2<int, 5> myArr1;
    Array2<double, 5> myArr2;
    myArr2.getSize();

}