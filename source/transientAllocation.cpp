// transientAllocation.cpp

#include <memory>

constexpr auto correctRelease() {
     auto* p = new int[2020];
     delete [] p;
     return 2020;
}

constexpr auto forgottenRelease() {
    auto* p = new int[2020];  
    return 2020;
}

constexpr auto falseRelease() {
    auto* p = new int[2020];
    delete p;            
    return 2020;
}

int main() {

    constexpr int res1 = correctRelease();
    constexpr int res2 = forgottenRelease();
    constexpr int res3 = falseRelease();

}