// priority_queueSchedulerPriority.cpp

#include <concepts>
#include <coroutine>
#include <functional>
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

using job = std::pair<int, std::coroutine_handle<>>;

template <typename Updater = std::identity,                         
          typename Comperator = std::ranges::less>                   
requires std::invocable<decltype(Updater()), int> &&                
         std::predicate<decltype(Comperator()), job, job>             
class Scheduler {

  std::priority_queue<job, std::vector<job>, Comperator> _prioTasks;

  public: 
    void emplace(int prio, std::coroutine_handle<> task) {
      _prioTasks.push(std::make_pair(prio, task));
    }

    void schedule() {
      Updater upd = {};                                            
      while(!_prioTasks.empty()) {
        auto [prio, task] = _prioTasks.top();
        _prioTasks.pop();
        task.resume();

        if(!task.done()) { 
          _prioTasks.push(std::make_pair(upd(prio), task));          
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
  for (int i = 0; i <= 3; ++i ) { 
    std::cout << name << " execute " << i << "\n";                  
    co_await std::suspend_always();
  }
  co_await std::suspend_always();
  std::cout << name << " finish\n";
}


int main() {

  std::cout << '\n';

  std::string taskA = "TaskA";
  std::string taskB = "  TaskB";
  std::string taskC = "    TaskC";

  Scheduler scheduler1;                                          

  scheduler1.emplace(0, createTask(taskA).get_handle());
  scheduler1.emplace(1, createTask(taskB).get_handle());
  scheduler1.emplace(2, createTask(taskC).get_handle());

  scheduler1.schedule();

  std::cout << '\n';

  Scheduler<decltype([](int a) { return a - 1; })> scheduler2;        

  scheduler2.emplace(0, createTask(taskA).get_handle());
  scheduler2.emplace(1, createTask(taskB).get_handle());
  scheduler2.emplace(2, createTask(taskC).get_handle());

  scheduler2.schedule();

  std::cout << '\n';

}