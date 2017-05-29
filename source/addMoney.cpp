// addMoney.cpp

#include <functional>
#include <iostream>
#include <thread>
#include <vector>

struct Account{
  int balance{100};                              // 1
};

void addMoney(Account& to, int amount){
  to.balance += amount;                          // 2
}

int main(){
  
  std::cout << std::endl;

  Account account;
  
  std::vector<std::thread> vecThreads(100);
  
                                                 // 3
  for (auto& thr: vecThreads) thr = std::thread( addMoney, std::ref(account), 50);
  
  for (auto& thr: vecThreads) thr.join();
  
                                                 // 4
  std::cout << "account.balance: " << account.balance << std::endl;
  
  std::cout << std::endl;

}
