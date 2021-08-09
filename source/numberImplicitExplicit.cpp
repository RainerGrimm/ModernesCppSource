// numberImplicitExplicit.cpp

#include <cmath>
#include <string>

template <typename T>
struct Number {
	int absValue() {
        return std::abs(val);
    }
  T val{};
};

// template class Number<std::string>;           // (2)
// template int Number<std::string>::absValue(); // (3)

int main() {
  
    Number<std::string> numb;
    // numb.absValue();                         // (1)
  
}