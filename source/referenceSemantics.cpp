// referenceSemantics.cpp

#include <functional>
#include <iostream>
#include <list>
#include <type_traits>
#include <vector>
 
int main() {

    std::cout << '\n';

    std::list<int> myList{1, 2, 3, 4, 5};
    std::vector<std::reference_wrapper<int>> myRefVector(myList.begin(), myList.end());

    for (auto l: myList) std::cout << l << " ";
    std::cout << "\n\n";

    for (auto& v: myRefVector) v *= v;

    for (auto l: myList) std::cout << l << " ";
    
    std::cout << "\n\n";
    
}