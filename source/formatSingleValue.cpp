// formatSingleValue.cpp

#include <format>
#include <iostream>

class SingleValue {                                          
 public: 
   SingleValue() = default;
   explicit SingleValue(int s): singleValue{s} {}
   int getValue() const {                                   
     return singleValue;
   }
 private:
   int singleValue{};
};

template<>                                                   
struct std::formatter<SingleValue> {
  constexpr auto parse(std::format_parse_context& context) { 
    return context.begin();
  }
  auto format(const SingleValue& sVal, std::format_context& context) const {  
    return std::format_to(context.out(), "{}", sVal.getValue());
  }
};

int main() {

  std::cout << '\n'; 

  SingleValue sVal0;
  SingleValue sVal2020{2020};
  SingleValue sVal2023{2023};

  std::cout << std::format("Single Value: {} {} {}\n", sVal0, sVal2020, sVal2023);
  std::cout << std::format("Single Value: {1} {1} {1}\n", sVal0, sVal2020, sVal2023);
  std::cout << std::format("Single Value: {2} {1} {0}\n", sVal0, sVal2020, sVal2023);

  std::cout << '\n';

}