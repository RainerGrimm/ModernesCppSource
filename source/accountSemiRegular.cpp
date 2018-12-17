// accountSemiRegular.cpp

#include <experimental/type_traits>
#include <iostream>

class Account{
public:
  Account() = default;
  Account(double b): balance(b){}
  double getAccount() const {
    return balance;
  }
private:
  double balance{0.0};
};

template<typename T>
using equal_comparable_t = decltype(std::declval<T&>() == std::declval<T&>());

template<typename T>
struct isEqualityComparable: 
       std::experimental::is_detected<equal_comparable_t, T>
       {};

template<typename T>
struct isSemiRegular: std::integral_constant<bool,
                                      std::is_default_constructible<T>::value &&
                                      std::is_copy_constructible<T>::value &&
                                      std::is_copy_assignable<T>::value &&
                                      std::is_move_constructible<T>::value &&
                                      std::is_move_assignable<T>::value &&
                                      std::is_destructible<T>::value &&
                                      std::is_swappable<T>::value >{};

template<typename T>
struct isRegular: std::integral_constant<bool, 
                                         isSemiRegular<T>::value &&
                                         isEqualityComparable<T>::value >{};

int main(){

    std::cout << std::boolalpha << std::endl;

    std::cout << "isSemiRegular<Account>::value: " << isSemiRegular<Account>::value << std::endl;
    std::cout << "isRegular<Account>::value: " << isRegular<Account>::value << std::endl;

    std::cout << std::endl;

}




