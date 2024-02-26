// internationalization.cpp

#include <chrono>
#include <exception>
#include <iostream>
#include <thread>

std::locale createLocale(const std::string& localString) {                         
  try {
    return std::locale{localString};       
  }
  catch (const std::exception& e) {
    return std::locale{""};
  }
}

int main() {

    std::cout << '\n';

    using namespace std::literals;

    std::locale loc = createLocale("de_DE");

    std::cout << "Default locale: " << std::format("{:}", 2023) << '\n';
    std::cout << "German locale:  " << std::format(loc, "{:L}", 2023) << '\n';    

    std::cout << '\n';

    std::cout << "Default locale: " << std::format("{:}", 2023.05) << '\n';
    std::cout << "German locale:  " << std::format(loc, "{:L}", 2023.05) << '\n'; 

    std::cout << '\n';

    auto start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(33ms);
    auto end = std::chrono::steady_clock::now();

    const auto duration = end - start;

    std::cout << "Default locale: " << std::format("{:}", duration) << '\n';
    std::cout << "German locale:  " << std::format(loc, "{:L}", duration) << '\n'; 

    std::cout << '\n';

    const auto now = std::chrono::system_clock::now();
    std::cout << "Default locale: " << std::format("{}\n", now);
    std::cout << "German locale:  " << std::format(loc, "{:L}\n", now);            

    std::cout << '\n';

}
