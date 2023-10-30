// cachingRanges.cpp

#include <numeric>
#include <iostream>
#include <ranges>
#include <vector>
 
int main() {

    std::vector<int> vec(1'000'000);
    std::iota(vec.begin(), vec.end(), 0);

    for (int i: vec | std::views::filter([](auto v) { return v > 1000; }) 
                    | std::views::take(5)) {
                        std::cout << i << " ";  // 1001 1002 1003 1004 1005
                    }
    
}