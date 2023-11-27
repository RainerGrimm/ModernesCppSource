// // priority_queueSchedulerSimplified.cpp

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

};


Task createTask(const std::string& name) {
  std::cout << name << " start\n";
  co_await std::suspend_always();
  std::cout << name << " execute\n";
  co_await std::suspend_always();
  std::cout << name << " finish\n";
}


int main() {

  std::cout << '\n';

  Scheduler scheduler1;

  scheduler1.emplace(0, createTask("TaskA").get_handle());
  scheduler1.emplace(1, createTask("  TaskB").get_handle());

  scheduler1.schedule();

  std::cout << '\n';

  Scheduler scheduler2;

  scheduler2.emplace(1, createTask("TaskA").get_handle());
  scheduler2.emplace(0, createTask("  TaskB").get_handle());

  scheduler2.schedule();

  std::cout << '\n';

}