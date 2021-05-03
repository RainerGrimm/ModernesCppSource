// number.cpp

#include <cmath>
#include <string>

template <typename T>
struct Number {
	int absValue() {
        return std::abs(val);
    }
  T val{};
};

int main() {
  
    Number<std::string> numb;
    // numb.absValue();       // (1)
  
}