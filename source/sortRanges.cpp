// sortRanges.cpp

#include <algorithm>
#include <iostream>
#include <vector>

int main()  {

    std::vector<int> myVec{-3, 5, 0, 7, -4};
    std::ranges::sort(myVec);
    for (auto v: myVec) std::cout << v << " "; // -4, -3, 0, 5, 7

}