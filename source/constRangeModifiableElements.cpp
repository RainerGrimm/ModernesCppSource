// constRangeModifiableElements.cpp

#include <iostream>
#include <span>
#include <vector>

void printMe(std::span<int> container) {
    
    std::cout << "container.size(): " << container.size() << '\n';  
    for (auto e : container) std::cout << e << ' ';
    std::cout << "\n\n";
}

int main() {

    std::cout << '\n';

    std::vector<int> origVec{1, 2, 2, 4, 5};

    // Modifiable range of modifiable elements
    std::vector<int> dynamVec = origVec;
    dynamVec[2] = 3;
    dynamVec.push_back(6);
    printMe(dynamVec);

    // Constant range of constant elements
    const std::vector<int> constVec = origVec;
    // constVec[2] = 3;        ERROR
    // constVec.push_back(6);  ERROR
    std::span<const int> constSpan(origVec);
    // constSpan[2] = 3;       ERROR

    // Constant range of modifiable elements
    std::span<int> dynamSpan{origVec};
    dynamSpan[2] = 3;
    printMe(dynamSpan);

    std::cout << '\n';

}