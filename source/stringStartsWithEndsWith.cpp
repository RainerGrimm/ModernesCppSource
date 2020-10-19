// stringStartsWithEndsWith.cpp

#include <iostream>
#include <string_view>
#include <string>
 
template <typename PrefixType>
void startsWith(const std::string& str, PrefixType prefix) {
    std::cout << "            starts with " << prefix << ": " 
	          << str.starts_with(prefix) << '\n';
}

template <typename SuffixType>
void endsWith(const std::string& str, SuffixType suffix) {
    std::cout << "            ends with " << suffix << ": " 
	          << str.ends_with(suffix) << '\n';
}
 
int main() {

    std::cout << std::endl;
    
    std::cout << std::boolalpha;
    
    std::string helloWorld("Hello World");
    
    std::cout << helloWorld << std::endl;
 
    startsWith(helloWorld, helloWorld);
 
    startsWith(helloWorld, std::string_view("Hello"));
 
    startsWith(helloWorld, 'H');
    
    std::cout << "\n\n"; 
    
    std::cout << helloWorld << std::endl;
 
    endsWith(helloWorld, helloWorld);
 
    endsWith(helloWorld, std::string_view("World"));
 
    endsWith(helloWorld, 'd');
 
}