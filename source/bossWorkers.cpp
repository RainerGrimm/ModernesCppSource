// bossWorkers.cpp

#include <iostream>
#include <mutex>
#include <latch>
#include <thread>

std::latch workDone(6);
std::latch goHome(1);

std::mutex coutMutex;

void synchronizedOut(const std::string s) {
    std::lock_guard<std::mutex> lo(coutMutex);
    std::cout << s;
}

class Worker {
 public:
     Worker(std::string n): name(n) { };
  
      void operator() (){
          // notify the boss when work is done
          synchronizedOut(name + ": " + "Work done!\n");
          workDone.count_down();

          // waiting before going home
          goHome.wait();
          synchronizedOut(name + ": " + "Good bye!\n");
      }
 private:
    std::string name;
};

int main() {

    std::cout << '\n';

    std::cout << "BOSS: START WORKING! " << '\n';
  
    Worker herb("  Herb");
    std::thread herbWork(herb);
  
    Worker scott("    Scott");
    std::thread scottWork(scott);
  
    Worker bjarne("      Bjarne");
    std::thread bjarneWork(bjarne);
  
    Worker andrei("        Andrei");
    std::thread andreiWork(andrei);
  
    Worker andrew("          Andrew");
    std::thread andrewWork(andrew);
  
    Worker david("            David");
    std::thread davidWork(david);
    
    workDone.wait();

    std::cout << '\n';

    goHome.count_down();

    std::cout << "BOSS: GO HOME!" << '\n';

    herbWork.join();
    scottWork.join();
    bjarneWork.join();
    andreiWork.join();
    andrewWork.join();
    davidWork.join();
  
}