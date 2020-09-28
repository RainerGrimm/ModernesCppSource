// containsElement.cpp

#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

template <typename AssozCont>
bool containsElement5(const AssozCont& assozCont) {
    return assozCont.contains(5);
}

int main() {
    
    std::cout << std::boolalpha;
    
    std::cout << std::endl;
    
    std::set<int> mySet{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "containsElement5(mySet): " << containsElement5(mySet);
    
    std::cout << std::endl;
    
    std::unordered_set<int> myUnordSet{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "containsElement5(myUnordSet): " << containsElement5(myUnordSet);
    
    std::cout << std::endl;
    
    std::map<int, std::string> myMap{ {1, "red"}, {2, "blue"}, {3, "green"} };
    std::cout << "containsElement5(myMap): " << containsElement5(myMap);
    
    std::cout << std::endl;
    
    std::unordered_map<int, std::string> myUnordMap{ {1, "red"}, {2, "blue"}, {3, "green"} };
    std::cout << "containsElement5(myUnordMap): " << containsElement5(myUnordMap);
    
    std::cout << std::endl;
    
}

