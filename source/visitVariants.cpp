// visitVariants.cpp

#include <iostream>
#include <vector>
#include <typeinfo>
#include <variant>

  
int main(){
  
    std::cout << '\n';
  
    std::vector<std::variant<char, long, float, int, double, long long>>      // 1
               vecVariant = {5, '2', 5.4, 100ll, 2011l, 3.5f, 2017};
  
    for (auto& v: vecVariant){
        std::visit([](auto arg){std::cout << arg << " ";}, v);                // 2
    }
  
    std::cout << '\n';
  
    for (auto& v: vecVariant){
        std::visit([](auto arg){std::cout << typeid(arg).name() << " ";}, v); // 3
    }
  
    std::cout << "\n\n";
  
}