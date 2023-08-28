// optionalMonadic.cpp

#include <iostream>
#include <optional>
#include <vector>
#include <string>

std::optional<int> getInt(std::string arg) {
    try {
        return {std::stoi(arg)};
    }
    catch (...) {
        return { };
    }
}

 
int main() {
 
    std::cout << '\n'; 

    std::vector<std::optional<std::string>> strings = {"66", "foo", "-5"};

    for (auto s: strings) {
        auto res = s.and_then(getInt)
                  .transform( [](int n) { return n + 100;})
                  .transform( [](int n) { return std::to_string(n); })
                  .or_else([] { return std::optional{std::string("Error") }; });
        std::cout << *res << ' ';
    }

    std::cout << '\n';

}