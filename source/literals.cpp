// literals.cpp

#include <chrono>
#include <string>

int main() {

    {
        using namespace std::literals;

        std::string cppString = "C++ string literal"s;     
        auto aMinute = 60s;                                
        // duration aHour = 0.25h + 15min + 1800s;
    }

    {
        using namespace std::chrono;

        // std::string cppString = "C++ string literal"s;
        auto aMinute = 60s;
        duration aHour = 0.25h + 15min + 1800s;            
    }

    {
        using namespace std::chrono_literals;

        // std::string cppString = "C++ String literal"s;
        auto aMinute = 60s;
        // duration aHour = 0.25h + 15min + 1800s;
    }

}