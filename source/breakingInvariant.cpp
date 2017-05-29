// breakingInvariant.cpp

#include <atomic>
#include <functional>
#include <iostream>
#include <thread>

struct Account{
  std::atomic<int> balance{100};                               // 1
};
                                                               // 2
void transferMoney(int amount, Account& from, Account& to){
  using namespace std::chrono_literals;
  if (from.balance >= amount){
    from.balance -= amount;  
    std::this_thread::sleep_for(1ns);                           // 3
    to.balance += amount;
  }
}

 void printSum(Account& a1, Account& a2){
  std::cout << (a1.balance + a2.balance) << std::endl;         // 4
}

int main(){
  
  std::cout << std::endl;

  Account acc1;
  Account acc2;
  
  std::cout << "Initial sum: ";                          
  printSum(acc1, acc2);                                        // 5
  
  std::thread thr1(transferMoney, 5, std::ref(acc1), std::ref(acc2));
  std::thread thr2(transferMoney, 13, std::ref(acc2), std::ref(acc1));
  std::cout << "Intermediate sum: ";                
  std::thread thr3(printSum, std::ref(acc1), std::ref(acc2));  // 6
  
  thr1.join();
  thr2.join();
  thr3.join();
                                                               // 7
  std::cout << "     acc1.balance: " << acc1.balance << std::endl;
  std::cout << "     acc2.balance: " << acc2.balance << std::endl;
  
  std::cout << "Final sum: ";
  printSum(acc1, acc2);                                        // 8
  
  std::cout << std::endl;

}