// classTemplateArgumentDeduction.cpp

#include <array>
#include <vector>
#include <mutex>
#include <memory>

int main() {
  
    std::array myArr{1, 2, 3};     // deduces std::array<int, 3> 
    std::vector myVec{1.5, 2.5};   // deduces std::vector<double>
 
    std::mutex mut;
    std::lock_guard myLock(mut);  // deduces std::lock_guard<mutex>(mut);
  
    std::pair myPair(5, 5.5);     // deduces std::pair<int, double>
    std::tuple myTup(5, myArr, myVec); // deduces std::tuple<int, 
                                       // std::array<int, 3>, std::vector<double>>
}