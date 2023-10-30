// cachingIssuesRanges.cpp

#include <concepts>
#include <forward_list>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

void printElements(std::ranges::input_range auto&& rang) {
    for (int i: rang) {
        std::cout << i << " ";  
    }
    std::cout << '\n';
}
 
int main() {

    std::cout << '\n';

    std::vector<int> vec{-3, 10, 4, -7, 9, 0, 5, -5};
    std::forward_list<int> forL{-3, 10, 4, -7, 9, 0, 5, -5};

    auto first5Vector = vec | std::views::filter([](auto v) { return v > 0; }) 
                            | std::views::take(5);

    auto first5ForList = forL | std::views::filter([](auto v) { return v > 0; }) 
                              | std::views::take(5);            

    printElements(first5Vector);           // 10 4 9 5
    printElements(first5ForList);          // 10 4 9 5
    
    std::cout << '\n';

    vec.insert(vec.begin(), 10);
    forL.insert_after(forL.before_begin(), 10);


    printElements(first5Vector);           // -3 10 4 9 5
    printElements(first5ForList);          // 10 4 9 5

    std::cout << '\n';

    auto first5VectorCopy{first5Vector}; 
    auto first5ForListCopy{first5ForList}; 

    printElements(first5VectorCopy);       // -3 10 4 9 5
    printElements(first5ForListCopy);      // 10 10 4 9 5
    
    std::cout << '\n';

}
