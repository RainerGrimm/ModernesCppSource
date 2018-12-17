// isSmaller.cpp

#include <iostream>

class Account{
public:
  Account() = default;
  Account(double b): balance(b){}
  double getBalance() const {
    return balance;
  }
private:
  double balance{0.0};
};

template<typename T>
bool isSmaller(T fir, T sec){
    return fir < sec;
}

int main(){

    std::cout << std::boolalpha << std::endl;

    double firDoub{};
    double secDoub{2014.0};

    std::cout << "isSmaller(firDoub, secDoub): " << isSmaller(firDoub, secDoub) << std::endl;

    Account firAcc{};
    Account secAcc{2014.0};

    std::cout << "isSmaller(firAcc, secAcc): " << isSmaller(firAcc, secAcc) << std::endl;
    
    std::cout << std::endl;

}

   

   

  
    
