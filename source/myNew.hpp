// myNew.hpp

#ifndef MY_NEW
#define MY_NEW

#include <cstdlib>
#include <iostream>
#include <new>

static std::size_t alloc{0};
static std::size_t dealloc{0};

void* operator new(std::size_t sz){
    alloc+= 1;
    return std::malloc(sz);
}

void operator delete(void* ptr) noexcept{
    dealloc+= 1;
    std::free(ptr);
}

void getInfo(){
    
    std::cout << std::endl;
 
    std::cout << "Number of allocations: " << alloc << std::endl;
    std::cout << "Number of deallocations: " << dealloc << std::endl;
    
    std::cout << std::endl;
}

#endif // MY_NEW