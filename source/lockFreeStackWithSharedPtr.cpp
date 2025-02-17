// lockFreeStackWithSharedPtr.cpp

#include <atomic>
#include <future>
#include <iostream>
#include <stdexcept>
#include <memory>

template<typename T>
class LockFreeStack {
 public:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
    };
    std::shared_ptr<Node> head;
 public:
    LockFreeStack() = default;
    LockFreeStack(const LockFreeStack&) = delete;
    LockFreeStack& operator= (const LockFreeStack&) = delete;
   
    void push(T val) {
        auto newNode = std::make_shared<Node>();
        newNode->data = val;
        newNode->next = std::atomic_load(&head);
        while( !std::atomic_compare_exchange_strong(&head, &newNode->next, newNode) );
    }

    T topAndPop() {
        auto oldHead = std::atomic_load(&head);
        while( oldHead && !std::atomic_compare_exchange_strong(&head, &oldHead, std::atomic_load(&oldHead->next)) ) {
            if ( !oldHead ) throw std::out_of_range("The stack is empty!");
        }
        return oldHead->data;
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