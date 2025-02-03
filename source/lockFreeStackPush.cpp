// lockFreeStackPush.cpp

#include <atomic>
#include <iostream>

template<typename T>
class LockFreeStackPush {
 private:
    struct Node {
        T data;
        Node* next;
        Node(T d): data(d), next(nullptr) {}
    };
    std::atomic<Node*> head;
 public:
    LockFreeStackPush() = default;
    LockFreeStackPush(const LockFreeStackPush&) = delete;
    LockFreeStackPush& operator= (const LockFreeStackPush&) = delete;
   
    void push(T val) {
        Node* const newNode = new Node(val);                            // 1
        newNode->next = head.load();                                    // 2
        while( !head.compare_exchange_strong(newNode->next, newNode) ); // 3
    }
};
   
int main(){

    LockFreeStackPush<int> lockFreeStack;
    lockFreeStack.push(5);
    
    LockFreeStackPush<double> lockFreeStack2;
    lockFreeStack2.push(5.5);
    
    LockFreeStackPush<std::string> lockFreeStack3;
    lockFreeStack3.push("hello");

}