// threadLocallSummation.cpp

#include <atomic>
#include <iostream>
#include <random>
#include <thread>
#include <utility>
#include <vector>

constexpr long long size = 10000000;   

constexpr long long fir =  2500000;
constexpr long long sec =  5000000;
constexpr long long thi =  7500000;
constexpr long long fou = 10000000;

thread_local unsigned long long tmpSum = 0;

void sumUp(std::atomic<unsigned long long>& sum, const std::vector<int>& val, 
           unsigned long long beg, unsigned long long end) {
    for (auto i = beg; i < end; ++i){
        tmpSum += val[i];
    }
    sum.fetch_add(tmpSum);
}

int main(){

  std::cout << '\n';

  std::vector<int> randValues;
  randValues.reserve(size);

  std::mt19937 engine;
  std::uniform_int_distribution<> uniformDist(1, 10);
  for (long long i = 0; i < size; ++i) 
      randValues.push_back(uniformDist(engine));
 
  std::atomic<unsigned long long> sum{}; 
  
  std::thread t1(sumUp, std::ref(sum), std::ref(randValues), 0, fir);
  std::thread t2(sumUp, std::ref(sum), std::ref(randValues), fir, sec);
  std::thread t3(sumUp, std::ref(sum), std::ref(randValues), sec, thi);
  std::thread t4(sumUp, std::ref(sum), std::ref(randValues), thi, fou);   
  
  t1.join();
  t2.join();
  t3.join();
  t4.join();

  std::cout << "Result: " << sum << '\n';

  std::cout << '\n';

}
