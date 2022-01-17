// dp_6.cpp
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

int myrand(int min, int max) {
  return rand()%(max-min)+min;
}

void lock(std::atomic_flag& m) {
  while (m.test_and_set())
    ; // busy waiting
}

void unlock(std::atomic_flag& m) {
  m.clear();
}

void phil(int ph, std::atomic_flag& ma, std::atomic_flag& mb) {
  while(true) {
    int duration=myrand(1000, 2000);
    std::cout<<ph<<" thinks "<<duration<<"ms\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));

    lock(ma);
    std::cout<<"\t\t"<<ph<<" got ma\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    lock(mb);
    std::cout<<"\t\t"<<ph<<" got mb\n";

    duration=myrand(1000, 2000);
    std::cout<<"\t\t\t\t"<<ph<<" eats "<<duration<<"ms\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));

    unlock(mb);
    unlock(ma);
  }
}

int main() {
  std::cout<<"dp_6\n";
  srand(time(nullptr));

  std::atomic_flag m1, m2, m3, m4;
  unlock(m1);
  unlock(m2);
  unlock(m3);
  unlock(m4);

  std::thread t1([&] {phil(1, m1, m2);});
  std::thread t2([&] {phil(2, m2, m3);});
  std::thread t3([&] {phil(3, m3, m4);});
  std::thread t4([&] {phil(4, m1, m4);});

  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

// version 6 good busy waiting synchronization, with Resource hierarchy
// 2022-01-03, Andre Adrian, License CC BY-SA
