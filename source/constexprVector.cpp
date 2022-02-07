// constexprVector.cpp

#include <algorithm>
#include <iostream>
#include <vector>

constexpr int maxElement() {
    std::vector myVec = {1, 2, 4, 3};
    std::sort(myVec.begin(), myVec.end());
    return myVec.back();
}
int main() {

    std::cout <<  '\n';

    constexpr int maxValue = maxElement();
    std::cout << "maxValue: " << maxValue << '\n';

    constexpr int maxValue2 = [] {
        std::vector myVec = {1, 2, 4, 3};
        std::sort(myVec.begin(), myVec.end()) ;
        return myVec.back();
    }(); 

    std::cout << "maxValue2: " << maxValue2 << '\n';

    std::cout << '\n';

}