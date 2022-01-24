// semaphore.h
#include <mutex>
#include <condition_variable>
#include <limits>

namespace std {
  template <std::ptrdiff_t least_max_value
   = std::numeric_limits<std::ptrdiff_t>::max()>
  class counting_semaphore {
  public:
    counting_semaphore(std::ptrdiff_t desired) : counter(desired) {}

    counting_semaphore(const counting_semaphore&) = delete;
    counting_semaphore& operator=(const counting_semaphore&) = delete;

    inline void release(ptrdiff_t update = 1) {
      std::unique_lock<std::mutex> lock(mutex_);
      counter += update;
      cv.notify_one();
    }

    inline void acquire() {
      std::unique_lock<std::mutex> lock(mutex_);
      while (0 == counter) cv.wait(lock);
      --counter;
    }

  private:
    ptrdiff_t counter;
    std::mutex mutex_;
    std::condition_variable cv;
  };

  using binary_semaphore = counting_semaphore<1>;
}

// my C++20 compatible semaphore for C++11

// see https://en.cppreference.com/w/cpp/thread/counting_semaphore
// see http://eel.is/c++draft/thread.sema
// see https://github.com/cyanhill/semaphore
// see https://pages.cs.wisc.edu/~remzi/OSTEP/threads-cv.pdf fig 30.12
// see https://stackoverflow.com/questions/4792449/c0x-has-no-semaphores-how-to-synchronize-threads

// semaphore aquire() was called P(), wait(), sleep() or down()
// semaphore release() was called V(), notify(), wakeup() and up()

// 2022-01-01, Andre Adrian, License CC BY-SA
