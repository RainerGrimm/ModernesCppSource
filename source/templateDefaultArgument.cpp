// templateDefaultArguments.cpp

#include <functional>
#include <iostream>
#include <string>

class Account{
public:
  explicit Account(double b): balance(b){}
  double getBalance() const {
    return balance;
  }
private:
  double balance;
};

template <typename T, typename Pred = std::less<T>>                        // (1)
bool isSmaller(T fir, T sec, Pred pred = Pred() ){
  return pred(fir,sec);
}

int main(){

  std::cout << std::boolalpha << '\n';

  std::cout << "isSmaller(3,4): " << isSmaller(3,4) << '\n';                // (2) 
  std::cout << "isSmaller(2.14,3.14): "  << isSmaller(2.14,3.14) << '\n';
  std::cout << "isSmaller(std::string(abc),std::string(def)): " << 
                isSmaller(std::string("abc"),std::string("def")) << '\n';

  bool resAcc= isSmaller(Account(100.0),Account(200.0),                     // (3)
               [](const Account& fir, const Account& sec){ return fir.getBalance() < sec.getBalance(); });
  std::cout << "isSmaller(Account(100.0),Account(200.0)): " << resAcc << '\n';

  bool acc= isSmaller(std::string("3.14"),std::string("2.14"),              // (4)
            [](const std::string& fir, const std::string& sec){ return std::stod(fir) < std::stod(sec); });
  std::cout << "isSmaller(std::string(3.14),std::string(2.14)): " << acc << '\n';

  std::cout << '\n';

}
