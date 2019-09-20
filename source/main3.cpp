// main3.cpp

// #include <iostream>    // (1)
// #include <numeric>     // (1)
// #include <string>      // (1)
// #include <vector>      // (1)
import std.core; // (2)

import math3;

int main()
{

    std::cout << std::endl;

    // std::cout << "add(2000, 20): " << add(2000, 20) << std::endl;  // (3)

    std::vector<int> myVec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::string doc = "std::accumulate(myVec.begin(), myVec.end(), mult): ";
    auto prod = std::accumulate(myVec.begin(), myVec.end(), 1, mult);

    std::cout << doc << prod << std::endl;

    doTheMath();
}