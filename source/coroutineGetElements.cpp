// coroutineGetElements.cpp

#include <coroutine>
#include <memory>
#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct Generator {
    
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;
    
    Generator(handle_type h): coro(h) {}                      

    handle_type coro;
    std::shared_ptr<T> value;
    
    ~Generator() {  
        if ( coro ) coro.destroy();
    }
    Generator(const Generator&) = delete;
    Generator& operator = (const Generator&) = delete;
    Generator(Generator&& oth): coro(oth.coro) {
        oth.coro = nullptr;
    }
    Generator& operator = (Generator&& oth) {
        coro = oth.coro;
        oth.coro = nullptr;
        return *this;
    }
    T getNextValue() {
        coro.resume();
        return coro.promise().current_value;
    }
    struct promise_type {
        promise_type() {}                              
          
        ~promise_type() {}
        
        std::suspend_always initial_suspend() {            
            return {};
        }
        std::suspend_always final_suspend() noexcept {
            return {};
        }
        auto get_return_object() {      
            return Generator{handle_type::from_promise(*this)};
        }
      
        std::suspend_always yield_value(const T value) {    
            current_value = value;
            return {};
        }
        void return_void() {}
        void unhandled_exception() {
            std::exit(1);
        }

        T current_value;
    };

};

template <typename Cont>
Generator<typename Cont::value_type> getNext(Cont cont) {
    for (auto c: cont) co_yield c;
}

int main() {

    std::cout << '\n';
  
    std::string helloWorld = "Hello world";
    auto gen = getNext(helloWorld);
    for (int i = 0; i < helloWorld.size(); ++i) {
        std::cout << gen.getNextValue() << " ";
    }

    std::cout << "\n\n";

    auto gen2 = getNext(helloWorld);
    for (int i = 0; i < 5 ; ++i) {
        std::cout << gen2.getNextValue() << " ";
    }

    std::cout << "\n\n";

    std::vector myVec{1, 2, 3, 4 ,5};
    auto gen3 = getNext(myVec);
    for (int i = 0; i < myVec.size() ; ++i) {
        std::cout << gen3.getNextValue() << " ";
    }
    
    std::cout << '\n';

}