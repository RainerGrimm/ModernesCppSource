// producerConsumer.cpp

#include <algorithm>
#include <atomic>
#include <chrono>
#include <coroutine>
#include <functional>
#include <iostream>
#include <iterator>
#include <memory>
#include <source_location>
#include <thread>
#include <utility>
#include <vector>


void funcName(const std::source_location location = std::source_location::current()) {
    std::cout << location.function_name() << '\n';
}


template <typename Container>
void printContainer(const Container& container)
{
    typedef typename Container::value_type value_type;
    auto first = std::cbegin(container);
    auto last = std::cend(container);

    std::cout << " [";
    std::copy(first, std::prev(last), std::ostream_iterator<value_type>(std::cout, ", "));
    std::cout << *std::prev(last) << "]\n";
}




class [[nodiscard]] AudioDataResult final
{
    public:
        class promise_type;
        using handle_type = std::coroutine_handle<promise_type>;
        
        // Predefined interface that has to be specify in order to implement
        // coroutine's state-machine transitions
        class promise_type 
        {
            
            public:
                
                using value_type = std::vector<int>;

                AudioDataResult get_return_object() 
                {
                    return AudioDataResult{handle_type::from_promise(*this)};
                }
                std::suspend_never initial_suspend() noexcept { return {}; }
                std::suspend_always final_suspend() noexcept { return {}; }
                void return_void() {}
                void unhandled_exception() 
                {
                    std::rethrow_exception(std::current_exception());
                }

                // Generates the value and suspend the "producer"
                template <typename Data>
                requires std::convertible_to<std::decay_t<Data>, value_type>
                std::suspend_always yield_value(Data&& value) 
                {
                    data_ = std::forward<Data>(value);
                    data_ready_.store(true);
                    return {};
                }

                // Awaiter interface: for consumer waiting on data being ready
                struct AudioDataAwaiter 
                {
                    explicit AudioDataAwaiter(promise_type& promise) noexcept: promise_(promise) {}

                    bool await_ready() const { return promise_.data_ready_.load();}
                    
                    void await_suspend(handle_type) const
                    {
                        while(not promise_.data_ready_.exchange(false)) {
                             std::this_thread::yield(); 
                        }
                    }
                    // move assignment at client invocation side: const auto data = co_await audioDataResult;
                    // This requires that coroutine's result type provides the co_await unary operator
                    value_type&& await_resume() const 
                    {
                        return std::move(promise_.data_);
                    }

                    private: 
                        promise_type& promise_;
                };//Awaiter interface

        
            private:
                value_type data_;
                std::atomic<bool> data_ready_;
        }; //promise_type interface

        
        auto operator co_await() noexcept   
        {
            return promise_type::AudioDataAwaiter{handle_.promise()};
        }

        // Make the result type move-only, due to ownership over the handle
        AudioDataResult(const AudioDataResult&) = delete;
        AudioDataResult& operator=(const AudioDataResult&) = delete;

        AudioDataResult(AudioDataResult&& other) noexcept: handle_(std::exchange(other.handle_, nullptr)){}
        AudioDataResult& operator=(AudioDataResult&& other) noexcept 
        {
            using namespace std;
            AudioDataResult tmp = std::move(other);
            swap(*this, tmp);
            return *this;
        }

        // d-tor: RAII
        ~AudioDataResult() { if (handle_) {funcName(); handle_.destroy();}}

        // For resuming the producer - at the point when the data are consumed
        void resume() {if (not handle_.done()) { funcName(); handle_.resume();}}
    
    private:
        AudioDataResult(handle_type handle) noexcept : handle_(handle) {}

    private:
    handle_type handle_;
};


using data_type = std::vector<int>;
AudioDataResult producer(const data_type& data) 
{
    for (std::size_t i = 0; i < 5; ++i) {
        funcName();
        co_yield data;
    }
    co_yield data_type{}; // exit criteria
}

AudioDataResult consumer(AudioDataResult& audioDataResult) 
{
    while(true)
    {
        funcName();
        const auto data = co_await audioDataResult;
        if (data.empty()) {std::cout << "No data - exit!\n"; break;}
        std::cout << "Data received:";
        printContainer(data);
        audioDataResult.resume(); // resume producer
    }
}

int main() 
{
    {
        const data_type data = {1, 2, 3, 4};
        auto audioDataProducer = producer(data);
        std::thread t ([&]{auto audioRecorded = consumer(audioDataProducer);});
        t.join();
    }

    std::cout << "bye-bye!\n";
}