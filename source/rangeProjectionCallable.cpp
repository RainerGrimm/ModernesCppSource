// rangeProjectionCallable.cpp

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
 
struct PhoneBookEntry{ 
    std::string name;
    int number;
};

void printPhoneBook(const std::vector<PhoneBookEntry>& phoneBook) {
    for (const auto& entry: phoneBook) std::cout << "(" << entry.name << ", " 
                                                        << entry.number << ")";
    std::cout << "\n\n";
}
 
int main() {

    std::cout << '\n';

    std::vector<PhoneBookEntry> phoneBook{ {"Brown", 111}, {"Smith", 444}, 
    {"Grimm", 666}, {"Butcher", 222}, {"Taylor", 555}, {"Wilson", 333} };

    std::ranges::sort(phoneBook, {}, &PhoneBookEntry::name);           
    printPhoneBook(phoneBook);

    std::ranges::sort(phoneBook, {}, [](auto p){ return p.name;} );   
    printPhoneBook(phoneBook);

    std::ranges::sort(phoneBook, {}, [](auto p) { 
        return std::to_string(p.number) + p.name; 
    });
    printPhoneBook(phoneBook);

    std::ranges::sort(phoneBook, [](auto p, auto p2) { 
        return std::to_string(p.number) + p.name < std::to_string(p2.number) + p2.name; 
    });
    printPhoneBook(phoneBook);
    
}