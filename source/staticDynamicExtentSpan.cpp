// staticDynamicExtentSpan.cpp

#include <iostream>
#include <span>
#include <vector>

void printMe(std::span<int> container) {        
    
    std::cout << "container.size(): " << container.size() << '\n';
    for (auto e : container) std::cout << e << ' ';
    std::cout << "\n\n";
}

int main() {

    std::cout << '\n';

    std::vector myVec1{1, 2, 3, 4, 5};        
    std::vector myVec2{6, 7, 8, 9};

    std::span<int> dynamicSpan(myVec1);          
    std::span<int, 4> staticSpan(myVec2);        

    printMe(dynamicSpan);
    printMe(staticSpan);

    // staticSpan = dynamicSpan;    ERROR       
    dynamicSpan = staticSpan;                    

    printMe(staticSpan);                        

    std::cout << '\n';
    
}