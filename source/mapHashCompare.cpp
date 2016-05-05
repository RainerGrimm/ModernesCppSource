// mapHashCompare.cpp

#include <iostream>
#include <map>
#include <unordered_map>

int main(){

  std::cout << std::endl;

  std::cout << "C++ map: " << std::endl;
  std::map<std::string,int> m { {"Dijkstra",1972},{"Scott",1976} };
  m["Ritchie"] = 1983;
  std::cout << "    m[Ritchie]: " <<  m["Ritchie"] << "\n    ";
  for(auto p : m) std::cout << '{' << p.first << ',' << p.second << '}';
  m.erase("Scott");
  std::cout << "\n    ";
  for(auto p : m) std::cout << '{' << p.first << ',' << p.second << '}';
  m.clear();
  std::cout << std::endl;
  std::cout << "    m.size(): " << m.size() << std::endl;


  std::cout << std::endl;

  std::cout << "C++11 unordered_map: " << std::endl;
  std::unordered_map<std::string,int> um { {"Dijkstra",1972},{"Scott",1976} };
  um["Ritchie"] = 1983;
  std::cout << "    um[Ritchie]: " <<  um["Ritchie"] << "\n    ";
  for(auto p : um) std::cout << '{' << p.first << ',' << p.second << '}';
  um.erase("Scott");
  std::cout << "\n    ";
  for(auto p : um) std::cout << '{' << p.first << ',' << p.second << '}';
  um.clear();
  std::cout << std::endl;
  std::cout << "    um.size(): " << um.size() << std::endl;

  std::cout << std::endl;

}
