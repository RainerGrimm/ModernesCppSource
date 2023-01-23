// doubleFree.cpp

#include <cstddef>

class BigArray {

 public:
    BigArray(std::size_t len): len_(len), data_(new int[len]) {}

    ~BigArray(){
        delete[] data_;
    }

 private:
  size_t len_;
  int* data_;
};

int main(){
  
    BigArray bigArray1(1000);
    
    BigArray bigArray2(1000);
    
    bigArray2 = bigArray1;

}


