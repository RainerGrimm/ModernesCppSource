// toArray.cpp

#include <type_traits>
#include <utility>
#include <array>
 
int main(){
  
    auto arr1 = std::to_array("C-String Literal");
    static_assert(arr1.size() == 17);
 
    auto arr2 = std::to_array({ 0, 2, 1, 3 });
    static_assert(std::is_same<decltype(arr2), std::array<int, 4>>::value);
    
    auto arr3 = std::to_array<long>({ 0, 1, 3 });
    static_assert(std::is_same<decltype(arr3), std::array<long, 3>>::value);
 
    auto arr4 = std::to_array<std::pair<int, float>>( { { 3, .0f }, { 4, .1f }, { 4, .1e23f } });
    static_assert(arr4.size() == 3);
    static_assert(std::is_same<decltype(arr4), std::array<std::pair<int, float>, 3>>::value);
    
}