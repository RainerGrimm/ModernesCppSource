// localVariable.cpp

#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>

constexpr long long size = 100000000;

constexpr long long firBound = 25000000;
constexpr long long secBound = 50000000;
constexpr long long thiBound = 75000000;
constexpr long long fouBound = 100000000;

std::mutex myMutex;

void sumUp(unsigned long long& sum, const std::vector<int>& val, unsigned long long beg, unsigned long long end)
{
    unsigned long long tmpSum {};
    for (auto i = beg; i < end; ++i) {
        tmpSum += val[i];
    }
    std::lock_guard<std::mutex> lockGuard(myMutex);
    sum += tmpSum;
}

int main()
{

    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    std::mt19937 engine;
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    unsigned long long sum {};
    auto start = std::chrono::system_clock::now();

    std::thread t1(sumUp, std::ref(sum), std::ref(randValues), 0, firBound);
    std::thread t2(sumUp, std::ref(sum), std::ref(randValues), firBound, secBound);
    std::thread t3(sumUp, std::ref(sum), std::ref(randValues), secBound, thiBound);
    std::thread t4(sumUp, std::ref(sum), std::ref(randValues), thiBound, fouBound);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
    std::cout << "Time for addition " << dur.count() << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;
}