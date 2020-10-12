// formatChrono.cpp

#include <chrono>
#include <iostream>

int main() {
  using namespace std::literals::chrono_literals;
  std::cout << std::format("Default format: {} {}\n", 42s, 100ms) << "\n";
  std::cout << std::format("strftime-like format: {:%H:%M:%S}\n", 3h + 15min + 30s) << "\n";
}