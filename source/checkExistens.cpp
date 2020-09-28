// checkExistens.cpp

#include <set>
#include <iostream>

int main() {

    std::cout << std::endl;

    std::set mySet{3, 2, 1};
    if (mySet.find(2) != mySet.end()) {
        std::cout << "2 inside" << std::endl;
    }

    std::multiset myMultiSet{3, 2, 1, 2};
     if (myMultiSet.count(2)) {
        std::cout << "2 inside" << std::endl;
    } 

    std::cout << std::endl;

}
