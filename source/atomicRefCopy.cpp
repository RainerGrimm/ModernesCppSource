// atomicRefCopy.cpp

#include <atomic>
#include <iostream>

int main() {
    
    std::cout << std::endl;

    int val{5};
    int& ref = val;
    std::atomic<int> atomicRef(ref);
    ++atomicRef;
    std::cout << "ref: " << ref << std::endl;
    std::cout << "atomicRef.load(): " << atomicRef.load() << std::endl;
    
    std::cout << std::endl;

}
