// dataRaceRanges.cpp

#include <numeric>
#include <iostream>
#include <ranges>
#include <thread>
#include <vector>
 
int main() {

    std::vector<int> vec(1'000);
    std::iota(vec.begin(), vec.end(), 0);

    auto first5Vector = vec | std::views::filter([](auto v) { return v > 0; }) 
                            | std::views::take(5);

    std::jthread thr1([&first5Vector]{
        for (int i: first5Vector) {
            std::cout << i << " ";  
        }
    });


    for (int i: first5Vector) {
        std::cout << i << " ";  
    }

    std::cout << "\n\n";
    
}