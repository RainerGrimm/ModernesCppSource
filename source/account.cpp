// account.cpp

#include <iostream>

struct Account{                                  // 1
  int balance{100};
};

void transferMoney(int amount, Account& from, Account& to){
  if (from.balance >= amount){                  // 2
    from.balance -= amount;                    
    to.balance += amount;
  }
}

int main(){
  
  std::cout << std::endl;

  Account account1;
  Account account2;

  transferMoney(50, account1, account2);         // 3
  transferMoney(130, account2, account1);
  
  std::cout << "account1.balance: " << account1.balance << std::endl;
  std::cout << "account2.balance: " << account2.balance << std::endl;
  
  std::cout << std::endl;

}
