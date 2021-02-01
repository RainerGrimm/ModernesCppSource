// fullTimePartTimeWorkers.cpp

#include <iostream>
#include <barrier>
#include <mutex>
#include <string>
#include <thread>

std::barrier workDone(6);
std::mutex coutMutex;

void synchronizedOut(const std::string& s) noexcept {
    std::lock_guard<std::mutex> lo(coutMutex);
    std::cout << s;
}

class FullTimeWorker {
 public:
    FullTimeWorker(std::string n): name(n) { };
  
    void operator() () {
        synchronizedOut(name + ": " + "Morning work done!\n");
        workDone.arrive_and_wait();  // Wait until morning work is done
        synchronizedOut(name + ": " + "Afternoon work done!\n");
        workDone.arrive_and_wait();  // Wait until afternoon work is done
        
    }
 private:
    std::string name;
};

class PartTimeWorker {
 public:
    PartTimeWorker(std::string n): name(n) { };
  
    void operator() () {
        synchronizedOut(name + ": " + "Morning work done!\n");
        workDone.arrive_and_drop();  // Wait until morning work is done
    }
 private:
    std::string name;
};

int main() {

    std::cout << '\n';

    FullTimeWorker herb("  Herb");
    std::thread herbWork(herb);
  
    FullTimeWorker scott("    Scott");
    std::thread scottWork(scott);
  
    FullTimeWorker bjarne("      Bjarne");
    std::thread bjarneWork(bjarne);
  
    PartTimeWorker andrei("        Andrei");
    std::thread andreiWork(andrei);
  
    PartTimeWorker andrew("          Andrew");
    std::thread andrewWork(andrew);
  
    PartTimeWorker david("            David");
    std::thread davidWork(david);

    herbWork.join();
    scottWork.join();
    bjarneWork.join();
    andreiWork.join();
    andrewWork.join();
    davidWork.join();
  
}