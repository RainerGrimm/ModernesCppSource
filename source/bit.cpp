// bit.cpp

#include <bit>
#include <bitset>
#include <iostream>
 
int main() {
    
    std::uint8_t num= 0b00110010;
    
    std::cout << std::boolalpha;
    
    std::cout << "std::has_single_bit(0b00110010): " << std::has_single_bit(num) 
              << '\n';
    
    std::cout << "std::bit_ceil(0b00110010): " << std::bitset<8>(std::bit_ceil(num)) 
              << '\n';
    std::cout << "std::bit_floor(0b00110010): " 
              << std::bitset<8>(std::bit_floor(num)) << '\n';
    
    std::cout << "std::bit_width(5u): " << std::bit_width(5u) << '\n';
    
    std::cout << "std::rotl(0b00110010, 2): " << std::bitset<8>(std::rotl(num, 2)) 
              << '\n';
    std::cout << "std::rotr(0b00110010, 2): " << std::bitset<8>(std::rotr(num, 2)) 
              << '\n';
    
    std::cout << "std::countl_zero(0b00110010): " << std::countl_zero(num) << '\n';
    std::cout << "std::countl_one(0b00110010): " << std::countl_one(num) << '\n';
    std::cout << "std::countr_zero(0b00110010): " << std::countr_zero(num) << '\n';
    std::cout << "std::countr_one(0b00110010): " << std::countr_one(num) << '\n';
    std::cout << "std::popcount(0b00110010): " << std::popcount(num) << '\n';
    
}