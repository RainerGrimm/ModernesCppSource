// expectedMonadic.cpp

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
        auto res = getInt(s)
                   .transform( [](int n) { return n + 100; })
                   .transform( [](int n) { return std::to_string(n); });
        std::cout << *res << ' ';        
    }   

    std::cout << '\n';                                  
                                        
}