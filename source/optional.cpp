// optional.cpp

#include <optional>
#include <iostream>
#include <vector>

std::optional<int> getFirst(const std::vector<int>& vec){
  if ( !vec.empty() ) return std::optional<int>(vec[0]);
  else return std::optional<int>();
}

int main() {

    std::cout << '\n';
    
    std::vector<int> myVec{1, 2, 3};
    std::vector<int> myEmptyVec;
    
    auto myInt= getFirst(myVec);
    
    if (myInt){
        std::cout << "*myInt: "  << *myInt << '\n';
        std::cout << "myInt.value(): " << myInt.value() << '\n';
        std::cout << "myInt.value_or(2017):" << myInt.value_or(2017) << '\n';
    }
    
    std::cout << '\n';
    
    auto myEmptyInt= getFirst(myEmptyVec);
    
    if (!myEmptyInt){
        std::cout << "myEmptyInt.value_or(2017):" << myEmptyInt.value_or(2017) << '\n';
    }

    std::cout << '\n';

}