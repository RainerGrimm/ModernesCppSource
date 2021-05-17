// maxUnconstrainedConstrained.cpp

#include <iostream>
#include <concepts>

class Account {
 public:
    explicit Account(double b): balance(b) {}
    double getBalance() const { 
        return balance;
    }
 private:
    double balance;
};
  
Account max(const Account& lhs, const Account& rhs) {  // (1)
    std::cout << "max function\n";
    return (lhs.getBalance() > rhs.getBalance())? lhs : rhs;
}

template <std::totally_ordered T>                       // (2)
T max(const T& lhs,const T& rhs) {                     
    std::cout << "max restricted function template\n";
    return (lhs > rhs)? lhs : rhs;
}

template <typename T>                                   // (3)
T max(const T& lhs,const T& rhs) {                   
    std::cout << "max unrestriced function template\n";
    return (lhs > rhs)? lhs : rhs;
}


int main() {
  
    Account account1(50.5);
    Account account2(60.5);
    Account maxAccount = max(account1, account2);       // (4)
  
    int i1{50};
    int i2(60);
    int maxI = max(i2, i2);                             // (5)
  
}