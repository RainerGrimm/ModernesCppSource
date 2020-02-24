// rangesComposition.cpp

#include <iostream>
#include <ranges>
#include <string>
#include <map>


int main() {
    
    std::map<std::string, int> freqWord{ {"witch", 25}, {"wizard", 33}, {"tale", 45},
                                                   {"dog", 4}, {"cat", 34}, {"fish", 23} };
                                                
    std::cout << "All words: ";
    for (const auto& name : std::views::keys(freqWord)) { std::cout << name << " "; };                                               
                                                   
    std::cout << std::endl;
    
    std::cout << "All words reverse: ";
    for (const auto& name : std::views::keys(freqWord) | std::views::reverse) { std::cout << name << " "; };  
     
    std::cout << std::endl;
    
    std::cout << "The first 4 words: ";
    for (const auto& name : std::views::keys(freqWord) | std::views::take(4)) { std::cout << name << " "; }; 
    
    std::cout << std::endl;
                                
    std::cout << "All words starting with w: ";
    auto firstw = [](const std::string& name){ return name[0] == 'w'; };
    for (const auto& name : std::views::keys(freqWord) | std::views::filter(firstw)) { std::cout << name << " "; };
    
    std::cout << std::endl;
    
    auto lengthOf = [](const std::string& name){ return name.size(); };
    auto res = ranges::accumulate(std::views::keys(freqWord) | std::views::transform(lengthOf), 0);
    std::cout << "Sum of words: " << res << std::endl;
   
                           
}
