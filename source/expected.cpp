// expected.cpp

#include <iostream>
#include <expected>
#include <vector>
#include <string>

std::expected<int, std::string> getInt(std::string arg) {
    try {
        return std::stoi(arg);
    }
    catch (...) {
        return std::unexpected{std::string(arg + ": Error")};
    }
}

 
int main() {

    std::cout << '\n';

    std::vector<std::string> strings = {"66", "foo", "-5"};

    for (auto s: strings) {
        auto res = getInt(s);
        if (res) {
            std::cout << res.value() << ' ';
        }
        else {
            std::cout << res.error() << ' ';
        }
    }

    std::cout << '\n';

    for (auto s: strings) {
        auto res = getInt(s);
        std::cout << res.value_or(2023) << ' ';
    }

    std::cout << '\n';


}