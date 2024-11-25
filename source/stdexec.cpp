// stdexec.cpp

#include <exec/static_thread_pool.hpp>
#include <stdexec/execution.hpp>
#include <vector>

int main() {
  exec::static_thread_pool pool(8);

  auto sched = pool.get_scheduler();

  auto fun = [](int i) { return i * i; };
  auto work = stdexec::when_all(
      stdexec::starts_on(sched, stdexec::just(0) | stdexec::then(fun)),
      stdexec::starts_on(sched, stdexec::just(1) | stdexec::then(fun)),
      stdexec::starts_on(sched, stdexec::just(2) | stdexec::then(fun)));

  auto [i, j, k] = stdexec::sync_wait(std::move(work)).value();

  std::printf("%d %d %d", i, j, k);
}