// formatVector.cpp

#include <format>
#include <iostream>
#include <string>
#include <vector>
    
int main() {

  std::vector<int> myInts{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << std::format("{:}\n", myInts);
  std::cout << std::format("{::+}\n", myInts);
  std::cout << std::format("{::02x}\n", myInts);
  std::cout << std::format("{::b}\n", myInts);

  std::cout << '\n';

  std::vector<std::string> myStrings{"Only", "for", "testing", "purpose"};
  std::cout << std::format("{:}\n", myStrings);
  std::cout << std::format("{::.3}\n", myStrings);

}