// lazyFuture.cpp

#include <coroutine>
#include <iostream>
#include <memory>

template<typename T>
struct MyFuture {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    handle_type coro;

    MyFuture(handle_type h): coro(h) {
        std::cout << "    MyFuture::MyFuture" << '\n';
    }
    ~MyFuture() { 
        std::cout << "    MyFuture::~MyFuture" << '\n';
        if ( coro ) coro.destroy();
    }

    T get() {
        std::cout << "    MyFuture::get" << '\n';
        coro.resume();
        return coro.promise().result;
    }

    struct promise_type {
		T result;
        promise_type() {
           std::cout << "        promise_type::promise_type" << '\n';
        }
        ~promise_type() { 
            std::cout << "        promise_type::~promise_type" << '\n';
        }
        auto get_return_object() {
            std::cout << "        promise_type::get_return_object" << '\n';
            return MyFuture{handle_type::from_promise(*this)};
        }
        void return_value(T v) {
            std::cout << "        promise_type::return_value" << '\n';
            result = v;
        }
        std::suspend_always initial_suspend() {
            std::cout << "        promise_type::initial_suspend" << '\n';
            return {};
        }
        std::suspend_always final_suspend() {
            std::cout << "        promise_type::final_suspend" << '\n';
            return {};
        }
        void unhandled_exception() {
            std::exit(1);
        }
    };
};

MyFuture<int> createFuture() {
    std::cout << "createFuture" << '\n';
    co_return 2021;
}

int main() {

    std::cout << '\n';

    auto fut = createFuture();
    auto res = fut.get();
    std::cout << "res: " << res << '\n';

    std::cout << '\n';

}