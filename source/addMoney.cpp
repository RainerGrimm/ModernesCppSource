// addMoney.cpp

#include <functional>
#include <iostream>
#include <thread>
#include <vector>

struct Account{
  int balance{100};                             
};

void addMoney(Account& to, int amount){
  to.balance += amount;                         
}

int main(){
  
  std::cout << '\n';

  Account account;
  
  std::vector<std::thread> vecThreads(100);
  
                                                 
  for (auto& thr: vecThreads) thr = std::thread(addMoney, std::ref(account), 50);
  
  for (auto& thr: vecThreads) thr.join();
  
                                                 
  std::cout << "account.balance: " << account.balance << '\n';
  
  std::cout << '\n';

}
