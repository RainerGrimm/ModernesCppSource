// monostate.cpp

#include <iostream>
#include <string>
#include <unordered_map>

class Monostate {
  
 public:
    
    void addNumber(const std::string& na, int numb) {
        teleBook[na] = numb;
    }
 
    void getEntries () const {
        for (auto ent: teleBook){ 
            std::cout << ent.first << ": " << ent.second << '\n';
        }
    }
    
private:
    static std::unordered_map<std::string, int> teleBook;
 
};

std::unordered_map<std::string, int> Monostate::teleBook{};

int main() {
    
    std::cout << '\n';
    
    Monostate tele1;
    Monostate tele2;
    tele1.addNumber("grimm", 123);
    tele2.addNumber("huber", 456);
    tele1.addNumber("smith", 789);
    
    tele1.getEntries();
    
    std::cout << '\n';
    
    tele2.getEntries();
    
    std::cout << '\n';
    
}
