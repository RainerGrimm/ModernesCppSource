// rangesV3FilterTransform.cpp

#include <iostream>
#include <range/v3/all.hpp>
#include <vector>

int main() {

    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
  
    auto results = numbers | ranges::view::filter([](int n){ return n % 2 == 0; })
                           | ranges::view::transform([](int n){ return n * 2; });
                           
    for (auto v: results) std::cout << v << " ";     // 4 8 12

}
