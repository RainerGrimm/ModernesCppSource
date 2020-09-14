// subspan.cpp

#include <iostream>
#include <numeric>
#include <span>
#include <vector>

int main() {

    std::cout << std::endl;

    std::vector<int> myVec(20);
    std::iota(myVec.begin(), myVec.end(), 0);
    for (auto v: myVec) std::cout << v << " ";

    std::cout << "\n\n";

    std::span<int> mySpan(myVec);
    auto length = mySpan.size();

    auto count = 5;
    for (long unsigned int first = 0; first <= (length - count); first += count ) {
        for (auto ele: mySpan.subspan(first, count)) std::cout << ele << " ";
        std::cout << std::endl;
    }

}