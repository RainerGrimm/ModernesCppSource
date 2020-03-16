// mapFilter.cpp

#include "range.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <range/v3/all.hpp>
#include <string>
#include <vector>
#include <utility>

template <typename T>
struct AlwaysTrue {
    constexpr bool operator()(const T&) const {
        return true;
    }
};
    
template <typename Map, typename Seq, typename Filt = AlwaysTrue<typename Seq::value_type>>
auto mapFilter(Map map, Seq seq, Filt filt = Filt()) {
    
    typedef typename Seq::value_type value_type;
    using return_type = decltype(map(std::declval<value_type>()));  

    std::vector<return_type> result{};
    for (auto i :seq | ranges::views::filter(filt) 
                     | ranges::views::transform(map)) result.push_back(i);
    return result;
}

int main() {
    
    std::cout << std::endl;
    
    // [ i * i for i in range(1, 10) ] 
    auto res = mapFilter([](int i){ return i * i; }, range(1, 10) );
    
    // [ i * i for i in range(1, 10) if i % 2 == 1 ]
    res = mapFilter([](int i){ return i * i; }, range(1, 10) , 
                    [](auto i){ return i % 2 == 1; });
    
    for (auto v: res) std::cout << v << " ";
    
    std::cout << "\n\n";
    
    // [(len(word), word) for word in ["Only", "for", "testing", "purpose."]]
    std::vector<std::string> myStrings{"Only", "for", "testing", "purpose"};
    auto res2 = mapFilter([](const std::string& s){ return std::make_pair(s.size(), s); }, myStrings);
    
    // [(len(word), word) for word in ["Only", "for", "testing", "purpose."] if word[0].isupper()]
    myStrings = {"Only", "for", "testing", "purpose"};
    res2 = mapFilter([](const std::string& s){ return std::make_pair(s.size(), s); }, myStrings, 
                     [](const std::string& word){ return std::isupper(word[0]); });
    
    for (auto p: res2) std::cout << "(" <<  p.first << ", " << p.second << ") " ;
    
    std::cout << "\n\n";
    
    
    // freqWord = [(len(line), line) for line in open("/etc/services").read().split("\n")]
    // freqWord = map(lambda word: (len(word), word), open("/etc/services").read().split("\n"))
    // freqWord.sort(reverse = True)
    // freqWord[:3]    
    std::ifstream file("/etc/services", std::ios::in);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string text = buffer.str();

    std::vector<std::string> words = text | ranges::views::split('\n');
    auto lengthWords = mapFilter([](const std::string& s){ return std::make_pair(s.size(), s); }, words);
    std::sort(std::begin(lengthWords), std::end(lengthWords), std::greater());
    
    // len([line for line in open("/etc/services").read().split("\n") if 100 < len(line) < 150])
    words = text | ranges::views::split('\n');
    auto allLines = mapFilter([](const std::string& line){ return line; }, words, 
                              [](const std::string& line){ return 100 < line.size() && line.size() < 150; });
    std::cout << "Number of lines: " << allLines.size();
    
    std::cout << "\n\n";
}
