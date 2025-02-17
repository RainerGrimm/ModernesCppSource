 // atomicSmartPointer.cpp
 
#include <atomic>
#include <iostream>
#include <memory>

template <typename T>
struct Node {
    T data;
    std::shared_ptr<Node> next;   
};

int main() {    

    std::cout << '\n';

    std::cout << std::boolalpha;

    std::atomic<std::shared_ptr<Node<int>>> node;
    std::cout << "node.is_lock_free(): "  << node.is_lock_free() << '\n';

    std::cout << '\n';

}