// dp_10.cpp
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

int myrand(int min, int max) {
  return rand()%(max-min)+min;
}

std::mutex mo;

void phil(int ph, std::mutex& ma, std::mutex& mb) {
  while(true) {
    int duration=myrand(1000, 2000);
    {
      std::lock_guard<std::mutex> g(mo);
      std::cout<<ph<<" thinks "<<duration<<"ms\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));

    std::lock_guard<std::mutex> ga(ma);
    {
      std::lock_guard<std::mutex> g(mo);
      std::cout<<"\t\t"<<ph<<" got ma\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::lock_guard<std::mutex> gb(mb);
    {
      std::lock_guard<std::mutex> g(mo);
      std::cout<<"\t\t"<<ph<<" got mb\n";
    }

    duration=myrand(1000, 2000);
    {
      std::lock_guard<std::mutex> g(mo);
      std::cout<<"\t\t\t\t"<<ph<<" eats "<<duration<<"ms\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
  }
}

int main() {
  std::cout<<"dp_10\n";
  srand(time(nullptr));

  std::mutex m1, m2, m3, m4;

  std::thread t1([&] {phil(1, m1, m2);});
  std::thread t2([&] {phil(2, m2, m3);});
  std::thread t3([&] {phil(3, m3, m4);});
  std::thread t4([&] {phil(4, m1, m4);});

  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

// version 10 lock_guard mutex, cout mutex, with Resource hierarchy
// 2022-01-01, Andre Adrian, License CC BY-SA
