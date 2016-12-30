// moveAlgorithm.cpp
#include <numeric>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
 
class MyInt{
public:
    MyInt(int i_):i(i_){}
    
    // copy semantic
    MyInt(const MyInt&)= delete;
    MyInt& operator= (const MyInt&)= delete;
    
    // move semantic
    MyInt(MyInt&&)= default;
    MyInt& operator= (MyInt&&)= default;
    
    int getVal() const {
        return i;
    }
private:
    int i;
};

int main(){
    
    std::cout << std::endl;
    
    std::vector<MyInt> vecMyInt;
    for (auto i= 1; i <= 10; ++i){
        vecMyInt.push_back(std::move(MyInt(i)));
    }
    
    std::for_each(vecMyInt.begin(), vecMyInt.end(), [](MyInt& myInt){ std::cout << myInt.getVal() << " "; });
    
    std::cout << std::endl;
    
    auto myInt= MyInt(std::accumulate(vecMyInt.begin(), vecMyInt.end(),MyInt(1),[](MyInt& f, MyInt& s){ return f.getVal() * s.getVal(); }));
    
    std::cout << "myInt.getVal(): " << myInt.getVal() << std::endl;
    
    std::cout << std::endl;
    
}

