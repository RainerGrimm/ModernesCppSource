// iteratorProtocol.cpp

#include <array>

int main() {
   
    std::array<int, 5> myArr{1, 2, 3, 4, 5};
  	for (auto a: myArr) a;
  
}