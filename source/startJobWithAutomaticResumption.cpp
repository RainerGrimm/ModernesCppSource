// startJobWithAutomaticResumption.cpp

#include <coroutine>
#include <functional>
#include <iostream>
#include <random>

std::random_device seed;
auto gen = std::bind_front(std::uniform_int_distribution<>(0,1), 
                           std::default_random_engine(seed()));

struct MySuspendAlways {
    bool await_ready() const noexcept { 
        std::cout << "        MySuspendAlways::await_ready"  << '\n';
        return gen();
    }
    bool await_suspend(std::coroutine_handle<> handle) const noexcept {
        std::cout << "        MySuspendAlways::await_suspend"  << '\n';
        handle.resume();
        return true;

    }
    void await_resume() const noexcept {
        std::cout << "        MySuspendAlways::await_resume"  << '\n';
    }
};
 
struct Job { 
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;
    handle_type coro;
    Job(handle_type h): coro(h){}
    ~Job() {
        if ( coro ) coro.destroy();
    }

    struct promise_type {
        auto get_return_object() { 
            return Job{handle_type::from_promise(*this)};
        }
        MySuspendAlways initial_suspend() { 
            std::cout << "    Job prepared" << '\n';
            return {}; 
        }
        std::suspend_always final_suspend() noexcept {
            std::cout << "    Job finished" << '\n'; 
            return {}; 
        }
        void return_void() {}
        void unhandled_exception() {}
    
    };
};
 
Job performJob() {
    co_await std::suspend_never();
}
 
int main() {

    std::cout <<  "Before jobs" << '\n';

    performJob();
    performJob();
    performJob();
    performJob();

    std::cout <<  "After jobs" <<  '\n';

}