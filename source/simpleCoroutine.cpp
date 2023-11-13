// simpleCoroutine.cpp

#include <coroutine>
#include <iostream>

struct MyCoroutine {                          
    struct promise_type {
        MyCoroutine get_return_object() {
            return std::coroutine_handle<promise_type>::
            from_promise(*this);
        }
        std::suspend_always initial_suspend() {
            return {};
        }
        std::suspend_always final_suspend() noexcept {
            return {};
        }
        void return_void() {}
        void unhandled_exception() {}
    };
    MyCoroutine(std::coroutine_handle<promise_type> handle): handle{handle} {}
    
    void resume() { 
        handle.resume(); 
    }
    void destroy() { 
        handle.destroy(); 
    }
    
    std::coroutine_handle<promise_type> handle;
};

MyCoroutine simpleCoroutine() {                
    std::cout << "Start coroutine\n";
    co_await std::suspend_always{};
    std::cout << "Resume coroutine\n";
}

int main() {
    MyCoroutine coro = simpleCoroutine();
    std::cout << "Coroutine is not executed yet\n";
    coro.resume();
    std::cout << "Suspend coroutine\n";
    coro.resume();
    coro.destroy();
    return 0;
}
