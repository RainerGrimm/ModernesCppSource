// lockFreeStackWithGarbageCollection.cpp

#include <atomic>
#include <future>
#include <iostream>
#include <stdexcept>
#include <thread>

template<typename T>
class LockFreeStack {
 private:
    struct Node {
        T data;
        Node* next;
        Node(T d): data(d), next(nullptr){ }
    };

    std::atomic<Node*> head{nullptr};
    std::atomic<int> topAndPopCounter{};                                            // 1
    std::atomic<Node*> toBeDeletedNodes{nullptr};                                   // 2

    void tryToDelete(Node* oldHead) {                                              // 3
        if (topAndPopCounter  == 1) {                                              // 8
            Node* copyOfToBeDeletedNodes = toBeDeletedNodes.exchange(nullptr);     // 6
            if (topAndPopCounter == 1) deleteAllNodes(copyOfToBeDeletedNodes);     // 9
            else addNodeToBeDeletedNodes(copyOfToBeDeletedNodes); 
            delete oldHead;
        }
        else addNodeToBeDeletedNodes(oldHead);                                     // 7
    }

    void addNodeToBeDeletedNodes(Node* oldHead) { 
        oldHead->next = toBeDeletedNodes;
        while( !toBeDeletedNodes.compare_exchange_strong(oldHead->next, oldHead) ); // 10
    
    
    void deleteAllNodes(Node* currentNode) {                                      // 4
        while (currentNode) {
            Node* nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
     }

 public:
    LockFreeStack() = default;
    LockFreeStack(const LockFreeStack&) = delete;
    LockFreeStack& operator= (const LockFreeStack&) = delete;
   
    void push(T val) {
        Node* const newNode = new Node(val); 
        newNode->next = head.load();
        while( !head.compare_exchange_strong(newNode->next, newNode) );
    }

    T topAndPop() {
        ++topAndPopCounter;
        Node* oldHead = head.load();
        while( oldHead && !head.compare_exchange_strong(oldHead, oldHead->next) ) {
            if ( !oldHead ) throw std::out_of_range("The stack is empty!");
        }
        auto topElement = oldHead->data;
        tryToDelete(oldHead);                                                   // 5
        --topAndPopCounter;
        return topElement;
    }
};
   
int main(){

    LockFreeStack<int> lockFreeStack;
    
    auto fut = std::async([&lockFreeStack]{ lockFreeStack.push(2011); });
    auto fut1 = std::async([&lockFreeStack]{ lockFreeStack.push(2014); });
    auto fut2 = std::async([&lockFreeStack]{ lockFreeStack.push(2017); });
    
    auto fut3 = std::async([&lockFreeStack]{ return lockFreeStack.topAndPop(); });
    auto fut4 = std::async([&lockFreeStack]{ return lockFreeStack.topAndPop(); });
    auto fut5 = std::async([&lockFreeStack]{ return lockFreeStack.topAndPop(); });
    
    fut.get(), fut1.get(), fut2.get();
    
    std::cout << fut3.get() << '\n';
    std::cout << fut4.get() << '\n';
    std::cout << fut5.get() << '\n';

}