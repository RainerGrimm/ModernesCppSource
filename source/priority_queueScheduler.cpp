// priority_queueScheduler.cpp

#include <coroutine>
#include <iostream>
#include <queue>
#include <utility>


struct Task {

  struct promise_type {
    std::suspend_always initial_suspend() noexcept { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }

    Task get_return_object() { 
        return std::coroutine_handle<promise_type>::from_promise(*this); 
    }
    void return_void() {}
    void unhandled_exception() {}
  };

  Task(std::coroutine_handle<promise_type> handle): handle{handle}{}

  auto get_handle() { return handle; }

  std::coroutine_handle<promise_type> handle;
};

class Scheduler {
                                                            
  std::priority_queue<std::pair<int, std::coroutine_handle<>>> _prioTasks;

  public: 

    void emplace(int prio, std::coroutine_handle<> task) {   
      _prioTasks.push(std::make_pair(prio, task));
    }

    void schedule() {
      while(!_prioTasks.empty()) {                           
        auto [prio, task] = _prioTasks.top();
        _prioTasks.pop();
        task.resume();

        if(!task.done()) { 
          _prioTasks.push(std::make_pair(prio, task));        
        }
        else {
          task.destroy();
        }
      }
    }

    auto suspend() {
      return std::suspend_always{};
    }
};


Task TaskA(Scheduler& sch) {
  std::cout << "Hello from TaskA\n";
  co_await sch.suspend();
  std::cout << "Executing the TaskA\n";
  co_await sch.suspend();
  std::cout << "TaskA is finished\n";
}

Task TaskB(Scheduler& sch) {
  std::cout << "Hello from TaskB\n";
  co_await sch.suspend();
  std::cout << "Executing the TaskB\n";
  co_await sch.suspend();
  std::cout << "TaskB is finished\n";
}


int main() {

  std::cout << '\n';

  Scheduler scheduler1;

  scheduler1.emplace(0, TaskA(scheduler1).get_handle());         
  scheduler1.emplace(1, TaskB(scheduler1).get_handle());

  scheduler1.schedule();

  std::cout << '\n';

  Scheduler scheduler2;

  scheduler2.emplace(1, TaskA(scheduler2).get_handle());      
  scheduler2.emplace(0, TaskB(scheduler2).get_handle());

  scheduler2.schedule();

  std::cout << '\n';

}