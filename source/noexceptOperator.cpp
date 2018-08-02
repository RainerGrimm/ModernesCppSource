// noexceptOperator.cpp

#include <iostream>
#include <array>
#include <vector>

class NoexceptCopy{
public:
  std::array<int, 5> arr{1, 2, 3, 4, 5};             // (2)
};

class NonNoexceptCopy{
public:
  std::vector<int> v{1, 2, 3, 4 , 5};                // (3)
};

template <typename T> 
T copy(T const& src) noexcept(noexcept(T(src))){     // (1)
  return src; 
}

int main(){
    
    NoexceptCopy noexceptCopy;
    NonNoexceptCopy nonNoexceptCopy;
    
    std::cout << std::boolalpha << std::endl;
    
    std::cout << "noexcept(copy(noexceptCopy)): " <<            // (4)
                  noexcept(copy(noexceptCopy)) << std::endl;
                   
    std::cout << "noexcept(copy(nonNoexceptCopy)): " <<      // (5)
                  noexcept(copy(nonNoexceptCopy)) << std::endl;

    std::cout << std::endl;

}
