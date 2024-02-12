// formatSingleValueDelegation.cpp

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

    std::formatter<int> formatter;

    constexpr auto parse(std::format_parse_context& context) {
        return formatter.parse(context);
    }

    auto format(const SingleValue& singleValue, std::format_context& context) const {
        return formatter.format(singleValue.getValue(), context);
    }

}; 

int main() {

    std::cout << '\n'; 

    SingleValue singleValue0;
    SingleValue singleValue2020{2020};
    SingleValue singleValue2023{2023};

    std::cout << std::format("{:*<10}", singleValue0) << '\n';
    std::cout << std::format("{:*^10}", singleValue2020) << '\n';
    std::cout << std::format("{:*>10}", singleValue2023) << '\n';

    std::cout << '\n';

}
