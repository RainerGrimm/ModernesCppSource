// filter.cpp

#include "range.hpp"

#include <fstream>
#include <iostream>
#include <range/v3/all.hpp>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

template <typename Func, typename Seq>
auto filter(Func func, Seq seq) {
    
    typedef typename Seq::value_type value_type;

    std::vector<value_type> result{};
    for (auto i : seq | ranges::views::filter(func)) result.push_back(i);
    
    return result;
}


int main() {
    
    std::cout << std::endl;
    
    // filter(lambda i: (i % 3) == 0 , range(20, 50))
    auto res = filter([](int i){ return (i % 3) == 0; }, range(20, 50) );
    for (auto v: res) std::cout << v << " ";
    
    // filter(lambda word: word[0].isupper(), ["Only", "for", "testing", "purpose"]) 
    std::vector<std::string> myStrings{"Only", "for", "testing", "purpose"};
    auto res2 = filter([](const std::string& s){ return static_cast<bool>(std::isupper(s[0])); }, myStrings);
     
    std::cout << "\n\n";
     
    for (auto word: res2) std::cout << word << std::endl;
    
    std::cout << std::endl;
    
    // len(filter(lambda line: line[0] == "#", open("/etc/services").readlines()))
    std::ifstream file("/etc/services", std::ios::in);
    std::vector<std::string> lines;
    std::string line;
    while(std::getline(file, line)){
        lines.push_back(line);
    }
    std::vector<std::string> commentLines = filter([](const std::string& s){  return s[0] == '#'; }, lines);
    
    std::cout << "Comment lines: " << commentLines.size() << "\n\n";
                                          
}
