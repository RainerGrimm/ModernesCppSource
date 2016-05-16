// performanceRefCopyShared.cpp

#include <chrono>
#include <memory>
#include <iostream>

constexpr long long mill= 100000000;

void byReference(std::shared_ptr<int>& refPtr){
  volatile auto tmpPtr(refPtr);
}

void byCopy(std::shared_ptr<int> cpyPtr){
  volatile auto tmpPtr(cpyPtr);
}


int main(){

    std::cout <<  std::endl;
    
    auto shrPtr= std::make_shared<int>(2011);
   
    auto start = std::chrono::steady_clock::now();
  
    for (long long i= 0; i <= mill; ++i) byReference(shrPtr);    
    
    std::chrono::duration<double> dur= std::chrono::steady_clock::now() - start;
    std::cout << "by reference: " << dur.count() << " seconds" << std::endl;
    
    start = std::chrono::steady_clock::now();
    
    for (long long i= 0; i<= mill; ++i){
        byCopy(shrPtr);
    }
    
    dur= std::chrono::steady_clock::now() - start;
    std::cout << "by copy: " << dur.count() << " seconds" << std::endl;
    
    std::cout << std::endl;
    
}