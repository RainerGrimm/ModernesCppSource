// lockFreeStackWithAtomicSharedPtr.cpp

#include <atomic>
#include <future>
#include <iostream>
#include <stdexcept>
#include <memory>

template<typename T>
class LockFreeStack {
 private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
    };
    std::atomic<std::shared_ptr<Node>> head;           // 1
 public:
    LockFreeStack() = default;
    LockFreeStack(const LockFreeStack&) = delete;
    LockFreeStack& operator= (const LockFreeStack&) = delete;
   
    void push(T val) {                              // 2
        auto newNode = std::make_shared<Node>();
        newNode->data = val;
        newNode->next = head;
        while( !head.compare_exchange_strong(newNode->next, newNode) );
    }

    T topAndPop() {
        auto oldHead = head.load();
        while( oldHead && !head.compare_exchange_strong(oldHead, oldHead->next) ) {
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