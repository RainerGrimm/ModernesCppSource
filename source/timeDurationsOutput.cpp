// timeDurationsOutput.cpp

#include <chrono>
#include <iostream>

int main() {

    std::cout << '\n';

    using namespace std::chrono_literals;

    std::cout << "5ns: " << 5ns << '\n';
    std::cout << "std::chrono::nanoseconds(5): " 
              << std::chrono::nanoseconds(5) << '\n';

    std::cout << '\n';

    std::cout << "5ms: " << 5ms << '\n';
    std::cout << "std::chrono::microseconds(5): " 
              << std::chrono::microseconds(5) << '\n';

    std::cout << '\n';

    std::cout << "5us: " << 5us << '\n';
    std::cout << "std::chrono::milliseconds(5): " 
              << std::chrono::milliseconds(5) << '\n';

    std::cout << '\n';

    std::cout << "5s: " << 5s << '\n';
    std::cout << "std::chrono::seconds(5): " << std::chrono::seconds(5) << '\n';

    std::cout << '\n';

    std::cout << "5min: " << 5min << '\n';
    std::cout << "std::chrono::minutes(5): " << std::chrono::minutes(5) << '\n';

    std::cout << '\n';

    std::cout << "5h: " << 5h << '\n';
    std::cout << "std::chrono::hours(5): " << std::chrono::hours(5) << '\n';

    std::cout << '\n';

    std::cout << "std::chrono::days(5): " << std::chrono::days(5) << '\n';

    std::cout << '\n';

    std::cout << "std::chrono::weeks(5): " << std::chrono::weeks(5) << '\n';

    std::cout << '\n';

    std::cout << "std::chrono::months(5): " << std::chrono::months(5) << '\n';

    std::cout << '\n';

    std::cout << "std::chrono::years(5): " << std::chrono::years(5) << '\n';  

    std::cout << '\n';

}