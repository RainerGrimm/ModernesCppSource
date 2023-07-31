// decayType.cpp

#include <type_traits>

int main() {
     
    // (1)
    // int[5] -> int* 
    static_assert(std::is_same<std::decay<int[5]>::type, int*>::value);             
    
    // (2)
    // void(int) -> void(*)(int)
    static_assert(std::is_same<std::decay<void(int)>::type, void(*)(int)>::value);  
    
    // (3)
    // const int -> int
    static_assert(std::is_same<std::decay<const int>::type, int>::value);           
    
    // (4)
    // const int& -> int
    static_assert(std::is_same<std::decay<const int&>::type, int>::value);          

}