// removeElements.cpp

#include <algorithm>
#include <iostream>
#include <vector>

int main() {

    std::cout << std::endl;

    std::vector myVec{-2, 3, -5, 10, 3, 0, -5 };

    for (auto ele: myVec) std::cout << ele << " ";
    std::cout << "\n\n";

    std::remove_if(myVec.begin(), myVec.end(), [](int ele){ return ele < 0; });
    for (auto ele: myVec) std::cout << ele << " ";

    std::cout << "\n\n";

}
