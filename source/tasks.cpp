// tasks.cpp

#include <chrono>
#include <future>
#include <iostream>
#include <random>
#include <thread>
#include <utility>
#include <vector>

constexpr long long size= 100000000;   

constexpr long long firBound=  25000000;
constexpr long long secBound=  50000000;
constexpr long long thiBound=  75000000;
constexpr long long fouBound= 100000000;

void sumUp(std::promise<unsigned long long>&& prom, const std::vector<int>& val, unsigned long long beg, unsigned long long end){
	unsigned long long sum={};
	for (auto i= beg; i < end; ++i){
	    sum += val[i];
    }
    prom.set_value(sum);
}

int main(){

  std::cout << std::endl;

  std::vector<int> randValues;
  randValues.reserve(size);

  std::mt19937 engine;
  std::uniform_int_distribution<> uniformDist(1,10);
  for ( long long i=0 ; i< size ; ++i) randValues.push_back(uniformDist(engine));
 
  std::promise<unsigned long long> prom1;
  std::promise<unsigned long long> prom2;
  std::promise<unsigned long long> prom3;
  std::promise<unsigned long long> prom4;
  
  auto fut1= prom1.get_future();
  auto fut2= prom2.get_future();
  auto fut3= prom3.get_future();
  auto fut4= prom4.get_future();
  
  
  auto start = std::chrono::system_clock::now();

  std::thread t1(sumUp,std::move(prom1),std::ref(randValues),0,firBound);
  std::thread t2(sumUp,std::move(prom2),std::ref(randValues),firBound,secBound);
  std::thread t3(sumUp,std::move(prom3),std::ref(randValues),secBound,thiBound);
  std::thread t4(sumUp,std::move(prom4),std::ref(randValues),thiBound,fouBound);
  
  auto sum= fut1.get() + fut2.get() + fut3.get() + fut4.get();
 
  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "Time for addition " << dur.count() << " seconds" << std::endl;
  std::cout << "Result: " << sum << std::endl;
  
  t1.join();
  t2.join();
  t3.join();
  t4.join();

  std::cout << std::endl;

}