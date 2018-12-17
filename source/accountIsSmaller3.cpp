// accountIsSmaller3.cpp

#include <functional>
#include <iostream>
#include <string>

class Account{
public:
    Account() = default;
    Account(double b): balance(b){}
    friend bool operator == (Account const& fir, Account const& sec) { 
        return fir.getBalance() == sec.getBalance();
    }
    double getBalance() const {
      return balance;
    }
private:
    double balance{0.0};
};

template <typename T, typename Pred = std::less<T> >    // (1)
bool isSmaller(T fir, T sec, Pred pred = Pred() ){      // (2)
  return pred(fir, sec);                                // (3)
}

int main(){

    std::cout << std::boolalpha << std::endl;
    
    double firDou{};
    double secDou{2014.0};

    std::cout << "isSmaller(firDou, secDou): " << isSmaller(firDou, secDou) << std::endl;

    Account firAcc{};
    Account secAcc{2014.0};
    
    auto res = isSmaller(firAcc, secAcc, [](const Account& fir, const Account& sec){
        return fir.getBalance() < sec.getBalance(); 
    });
    
    std::cout << "isSmaller(firAcc, secAcc): " <<  res << std::endl;
    
    std::cout << std::endl;
    
    std::string firStr = "AAA";
    std::string secStr = "BB";
     
    std::cout << "isSmaller(firStr, secStr): " <<  isSmaller(firStr, secStr) << std::endl;
    
     auto res2 = isSmaller(firStr, secStr, [](const std::string& fir, const std::string& sec){
        return fir.length() < sec.length(); 
    });
     
    std::cout << "isSmaller(firStr, secStr): " <<  res2 << std::endl;
    
    std::cout << std::endl;

}

   

   

  
    
