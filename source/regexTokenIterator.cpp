// regexTokenIterator.cpp

#include <iostream>
#include <string>
#include <regex>
#include <vector>

std::vector<std::string> splitAt(const std::string &text,                     // (6)
                                 const std::regex &reg) {
  std::sregex_token_iterator hitIt(text.begin(), text.end(), reg, -1);
  const std::sregex_token_iterator hitEnd;
  std::vector<std::string> resVec;
  for (; hitIt != hitEnd; ++hitIt)
    resVec.push_back(hitIt->str());
  return resVec;
}

int main() {

  std::cout << std::endl;

  const std::string text("3,-1000,4.5,-10.5,5e10,2e-5");                      // (1)

  const std::regex regNumber(
      R"([-+]?([0-9]+\.?[0-9]*|\.[0-9]+)([eE][-+]?[0-9]+)?)");                // (2)
  std::sregex_iterator numberIt(text.begin(), text.end(), regNumber);         // (3)
  const std::sregex_iterator numberEnd;
  for (; numberIt != numberEnd; ++numberIt) {                        
    std::cout << numberIt->str() << std::endl;                                // (4)
  }

  std::cout << std::endl;

  const std::regex regComma(",");
  std::sregex_token_iterator commaIt(text.begin(), text.end(), regComma, -1); // (5)
  const std::sregex_token_iterator commaEnd;
  for (; commaIt != commaEnd; ++commaIt) {
    std::cout << commaIt->str() << std::endl;
  }

  std::cout << std::endl;

  std::vector<std::string> resVec = splitAt(text, regComma);                  // (7)
  for (auto s : resVec)
    std::cout << s << " ";
  std::cout << "\n\n";

  resVec = splitAt("abc5.4def-10.5hij2e-5klm", regNumber);                    // (8)
  for (auto s : resVec)
    std::cout << s << " ";
  std::cout << "\n\n";

  std::regex regSpace(R"(\s+)");
  resVec = splitAt("abc  123  456\t789    def hij\nklm", regSpace);           // (9)
  for (auto s : resVec)
    std::cout << s << " ";
  std::cout << "\n\n";
}
