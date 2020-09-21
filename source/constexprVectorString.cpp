// constexprVectorString.cpp

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {

    std::cout << std::endl;

    constexpr std::vector myVec {15, -5, 0, 5, 10};
    constexpr std::sort(myVec.begin(), myVec.end());
    for (auto v: myVec) std::cout << v << " ";
    std::cout << "\n\n";

    using namespace std::string_literals;
    constexpr std::vector<std::string> myStringVec{"Stroustrup"s, "Vandevoorde"s, "Sutter"s, "Josuttis"s, "Wong"s };
    constexpr std::sort(myStringVec.begin(), myStringVec.end());
    for (auto s: myStringVec) std::cout << s << " ";

    std::cout << "\n\n";

}