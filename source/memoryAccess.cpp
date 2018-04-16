// memoryAcess.cpp

#include <forward_list>
#include <chrono>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <numeric>
#include <random>

const int SIZE = 100'000'000; 

template <typename T>
void sumUp(T& t, const std::string& cont){            // (6)
  
  std::cout << std::fixed << std::setprecision(10);

  auto begin= std::chrono::steady_clock::now();
  std::size_t res = std::accumulate(t.begin(), t.end(), 0LL);
  std::chrono::duration<double> last=  std::chrono::steady_clock::now() - begin;
  std::cout << cont <<  std::endl;
  std::cout << "time: " << last.count() << std::endl;
  std::cout << "res: " << res << std::endl;
  std::cout << std::endl;
 
  std::cout << std::endl;
     
}

int main(){
    
    std::cout << std::endl;
    
    std::random_device seed;                            // (1)
    std::mt19937 engine(seed());
    std::uniform_int_distribution<int> dist(0, 100);
    std::vector<int> randNumbers;
    randNumbers.reserve(SIZE);
    for (int i=0; i < SIZE; ++i){
        randNumbers.push_back(dist(engine));
    }
    
    {
      std::vector<int> myVec(randNumbers.begin(), randNumbers.end());
      sumUp(myVec,"std::vector<int>");                 // (2)
    }

    
    {
      std::deque<int>myDec(randNumbers.begin(), randNumbers.end());
      sumUp(myDec,"std::deque<int>");                 // (3)
    }
    
    {
      std::list<int>myList(randNumbers.begin(), randNumbers.end());
      sumUp(myList,"std::list<int>");                 // (4)
    }
    
    {
      std::forward_list<int>myForwardList(randNumbers.begin(), randNumbers.end());
      sumUp(myForwardList,"std::forward_list<int>");  // (5)
    } 
    
}
