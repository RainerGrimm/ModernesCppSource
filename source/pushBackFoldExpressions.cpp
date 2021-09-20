// pushBackFoldExpressions.cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
template<typename T, typename... Args>
void myPushBack(vector<T>& v, Args&&... args) {
    (v.push_back(args), ...);
}

int main() {

    std::cout << '\n';

    std::vector<int> myIntVec;
	myPushBack(myIntVec, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	for (auto v : myIntVec) std::cout << v << ' ';

    std::cout << "\n\n";

    std::vector myDoubleVec{1.1, 2.2, 3.3};
    myPushBack(myDoubleVec, 4.4, 5.5, 6.6);
    for (auto v: myDoubleVec) std::cout << v << ' ';

    std::cout << "\n\n";

}