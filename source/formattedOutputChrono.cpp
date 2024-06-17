// formattedOutputChrono.cpp

#include <chrono>
#include <iostream>
#include <thread>

int main() {

    std::cout << '\n';

    using namespace std::literals;

    auto start = std::chrono::steady_clock::now();   // (1)
    std::this_thread::sleep_for(33ms);
    auto end = std::chrono::steady_clock::now();     // (2)
    std::cout << std::format("The job took {} seconds\n", end - start);
    std::cout << std::format("The job took {:%S} seconds\n", end - start);

    std::cout << '\n';

    auto now = std::chrono::system_clock::now();    // (3)  
    std::cout << "now: " << now << '\n';
    std::cout << "Specifier {:%c}: " << std::format("{:%c}\n", now);
    std::cout << "Specifier {:%x}: " << std::format("{:%x}\n", now);
    std::cout << "Specifier {:%F}: " << std::format("{:%F}\n", now);
    std::cout << "Specifier {:%D}: " << std::format("{:%D}\n", now);
    std::cout << "Specifier {:%Y}: " << std::format("{:%Y}\n", now);
    std::cout << "Specifier {:%y}: " << std::format("{:%y}\n", now);
    std::cout << "Specifier {:%b}: " << std::format("{:%b}\n", now);
    std::cout << "Specifier {:%B}: " << std::format("{:%B}\n", now);
    std::cout << "Specifier {:%m}: " << std::format("{:%m}\n", now);
    std::cout << "Specifier {:%W}: " << std::format("{:%W}\n", now);
    std::cout << "Specifier {:%U}: " << std::format("{:%U}\n", now);
    std::cout << "Specifier {:%a}: " << std::format("{:%a}\n", now);
    std::cout << "Specifier {:%A}: " << std::format("{:%A}\n", now);
    std::cout << "Specifier {:%w}: " << std::format("{:%w}\n", now);
    std::cout << "Specifier {:%u}: " << std::format("{:%u}\n", now);
    std::cout << "Specifier {:%e}: " << std::format("{:%e}\n", now);
    std::cout << "Specifier {:%d}: " << std::format("{:%d}\n", now);

    std::cout << '\n';

}
