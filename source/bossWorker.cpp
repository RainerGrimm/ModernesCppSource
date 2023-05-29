// bossWorker.cpp

#include <future>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <utility>

int getRandomTime(int start, int end){
  
  std::random_device seed;
  std::mt19937 engine(seed());
  std::uniform_int_distribution<int> dist(start,end);
  
  return dist(engine);
};

class Worker{
public:
  explicit Worker(const std::string& n):name(n){};
  
  void operator() (std::promise<void>&& preparedWork, 
                   std::shared_future<void> boss2Worker){
      
    // prepare the work and notfiy the boss
    int prepareTime= getRandomTime(500, 2000);
    std::this_thread::sleep_for(std::chrono::milliseconds(prepareTime));
    preparedWork.set_value();
    std::cout << name << ": " << "Work prepared after " 
              << prepareTime << " milliseconds." << '\n';

    // still waiting for the permission to start working
    boss2Worker.wait();
  }    
private:
  std::string name;
};

int main(){
  
  std::cout << '\n';
  
  // define the std::promise => Instruction from the boss
  std::promise<void> startWorkPromise;

  // get the std::shared_future's from the std::promise
  std::shared_future<void> startWorkFuture= startWorkPromise.get_future();

  std::promise<void> herbPrepared;
  std::future<void> waitForHerb = herbPrepared.get_future();
  Worker herb("  Herb");
  std::thread herbWork(herb, std::move(herbPrepared), startWorkFuture);
  
  std::promise<void> scottPrepared;
  std::future<void> waitForScott = scottPrepared.get_future();
  Worker scott("    Scott");
  std::thread scottWork(scott, std::move(scottPrepared), startWorkFuture);
  
  std::promise<void> bjarnePrepared;
  std::future<void> waitForBjarne = bjarnePrepared.get_future();
  Worker bjarne("      Bjarne");
  std::thread bjarneWork(bjarne, std::move(bjarnePrepared), startWorkFuture);
  
  std::cout << "BOSS: PREPARE YOUR WORK.\n " << '\n';
  
  // waiting for the worker 
  waitForHerb.wait(), waitForScott.wait(), waitForBjarne.wait();
  
  // notify the workers that they should begin to work
  std::cout << "\nBOSS: START YOUR WORK. \n" << '\n';
  startWorkPromise.set_value();
  
  herbWork.join();
  scottWork.join();
  bjarneWork.join();
   
}
