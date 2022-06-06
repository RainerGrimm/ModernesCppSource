// sentinel.cpp

#include <iostream>
#include <algorithm>
#include <compare>
#include <vector>

struct Space {
bool operator== (auto pos) const {
        return *pos == ' '; 
    }
};

struct NegativeNumber {
    bool operator== (auto num) const {
        return *num < 0;   
    }
};

struct Sum {
    void operator()(auto n) { sum += n; }
    int sum{0};
};

int main() {

    std::cout << '\n';

    const char* rainerGrimm = "Rainer Grimm";
   
    std::ranges::for_each(rainerGrimm, Space{}, [] (char c) { std::cout << c; });
    std::cout << '\n';
    for (auto c: std::ranges::subrange{rainerGrimm, Space{}}) std::cout << c;
    std::cout << '\n';

    std::ranges::subrange rainer{rainerGrimm, Space{}};
    std::ranges::for_each(rainer, [] (char c) { std::cout << c << ' '; });
    std::cout << '\n';
    for (auto c: rainer) std::cout << c << ' ';
    std::cout << '\n';
  

    std::cout << "\n";


    std::vector<int> myVec{5, 10, 33, -5, 10};

    for (auto v: myVec) std::cout << v << " ";
    std::cout << '\n';

    auto [tmp1, sum] = std::ranges::for_each(myVec, Sum{});
    std::cout << "Sum: " << sum.sum << '\n';

    auto [tmp2, sum2] = std::ranges::for_each(std::begin(myVec), NegativeNumber{}, 
                                              Sum{} );
    std::cout << "Sum: " << sum2.sum << '\n';

    std::ranges::transform(std::begin(myVec), NegativeNumber{}, 
                           std::begin(myVec), [](auto num) { return num * num; });
    std::ranges::for_each(std::begin(myVec), NegativeNumber{}, 
                          [](int num) { std::cout << num << " "; });
    std::cout << '\n';
    for (auto v: std::ranges::subrange{ std::begin(myVec), NegativeNumber{}}) { 
        std::cout << v << " ";
    }

    std::cout << "\n\n";
    
}
