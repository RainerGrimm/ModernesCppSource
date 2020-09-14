// printSpan.cpp

#include <iostream>
#include <vector>
#include <array>
#include <span>

void printMe(std::span<int> container) {
    
    std::cout << "container.size(): " << container.size() << '\n';
    for(auto e : container) std::cout << e << ' ';
    std::cout << "\n\n";
}

int main() {
    
    std::cout << std::endl;
    
    int arr[]{1, 2, 3, 4};           
    printMe(arr);
    
    std::vector vec{1, 2, 3, 4, 5};     
    printMe(vec);

    std::array arr2{1, 2, 3, 4, 5, 6}; 
    printMe(arr2);
    
}
