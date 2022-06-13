// rangesAccess.cpp

#include <iterator>
#include <ranges>
#include <vector>

int main() {

    auto beginIt1 = std::begin(std::vector<int>{1, 2, 3});
    auto beginIt2 = std::ranges::begin(std::vector<int>{1, 2, 3});

}