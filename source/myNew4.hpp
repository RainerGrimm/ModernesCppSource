// myNew4.hpp

#ifndef MY_NEW4
#define MY_NEW4

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <new>
#include <array>

int const MY_SIZE= 10;

int counter= 0;

std::array<void* ,MY_SIZE> myAlloc{nullptr,};

void* newImpl(std::size_t sz,char const* file, int line){
    void* ptr= std::malloc(sz);
    std::cerr << file << ": " << line << " " <<  ptr << std::endl;
    myAlloc.at(counter++)= ptr;
    return ptr;
}

void* operator new(std::size_t sz,char const* file, int line){  
    return newImpl(sz,file,line);
}

void* operator new [](std::size_t sz,char const* file, int line){  
    return newImpl(sz,file,line);
}

void operator delete(void* ptr) noexcept{
    auto ind= std::distance(myAlloc.begin(),std::find(myAlloc.begin(),myAlloc.end(),ptr));
    myAlloc[ind]= nullptr;
    std::free(ptr);
}

#define new new(__FILE__, __LINE__)

void dummyFunction(){
    int* dummy= new int;
}

void getInfo(){
    
    std::cout << std::endl;
     
    std::cout << "Allocation: " << std::endl;
    for (auto i: myAlloc){
        if (i != nullptr ) std::cout << " " << i << std::endl;
    }
    
    std::cout << std::endl;
    
}

#endif // MY_NEW4
