// accociativeContainers.cpp

#include <iostream>
#include <map>
#include <string>
#include <utility>
 
using namespace std::literals;                                     // 1

template <typename Cont>
void printContainer(const Cont& cont, const std::string& mess){    // 2
  std::cout << mess;
  for (const auto& pa: cont){
    std::cout << "(" << pa.first << ": " << pa.second << ") ";
  }
  std::cout << std::endl;
}

int main(){
  
  std::map<int, std::string> ordMap{{1, "a"s}, {2, "b"}};          // 3
  ordMap.try_emplace(3, 3, 'C');
  ordMap.try_emplace(3, 3, 'c');
 
  printContainer(ordMap, "try_emplace: ");
  
  std::cout << std::endl;
  
  std::map<int, std::string> ordMap2{{3, std::string(3, 'C')},     // 4
                                      {4, std::string(3, 'D')}};
  ordMap2.insert_or_assign(5, std::string(3, 'e'));
  ordMap2.insert_or_assign(5, std::string(3, 'E'));
  
  printContainer(ordMap2, "insert_or_assign: ");                   // 5
  
  std::cout << std::endl;
  
  ordMap.merge(ordMap2);                                           // 6
  
  std::cout<< "ordMap.merge(ordMap2)" << std::endl;
  
  printContainer(ordMap, "  ordMap: ");
  printContainer(ordMap2, "  ordMap2: ");
  
  std::cout << std::endl;  
  
  std::cout << "extract and insert: " << std::endl;
                                                                           
  std::multimap<int, std::string> multiMap{{2017, std::string(3, 'F')}};  
  
  auto nodeHandle = multiMap.extract(2017);                        // 7
  nodeHandle.key() = 6;                                           
  ordMap.insert(std::move(nodeHandle));                         

  printContainer(ordMap, "   ordMap: ");
  printContainer(multiMap, "   multiMap: ");
  
}

