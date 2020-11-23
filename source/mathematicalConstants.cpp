// mathematicConstants.cpp

#include <iomanip>
#include <iostream>
#include <numbers>

int main() {
    
    std::cout << std::endl;
    
    std::cout<< std::setprecision(10);
    
    std::cout << "std::numbers::e: " <<  std::numbers::e << std::endl; 
    std::cout << "std::numbers::log2e: " <<  std::numbers::log2e << std::endl; 
    std::cout << "std::numbers::log10e: " <<  std::numbers::log10e << std::endl; 
    std::cout << "std::numbers::pi: " <<  std::numbers::pi << std::endl; 
    std::cout << "std::numbers::inv_pi: " <<  std::numbers::inv_pi << std::endl;
    std::cout << "std::numbers::inv_sqrtpi: " <<  std::numbers::inv_sqrtpi << std::endl; 
    std::cout << "std::numbers::ln2: " <<  std::numbers::ln2 << std::endl; 
    std::cout << "std::numbers::sqrt2: " <<  std::numbers::sqrt2 << std::endl; 
    std::cout << "std::numbers::sqrt3: " <<  std::numbers::sqrt3 << std::endl; 
    std::cout << "std::numbers::inv_sqrt3: " <<  std::numbers::inv_sqrt3 << std::endl;
    std::cout << "std::numbers::egamma: " <<  std::numbers::egamma << std::endl;
    std::cout << "std::numbers::phi: " <<  std::numbers::phi << std::endl;
    
    std::cout << std::endl;
    
}