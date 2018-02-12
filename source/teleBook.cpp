// teleBook.cpp

#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> getUpdatedTelephoneBook(){
    // generate a new, updated telephone book
    return {{"grimm",123}, {"huber", 456}, {"schmidt", 321}};
}

class TelephoneBook{
public:
    int getNumber(const std::string& name) const {
        auto ent = cache.find(name);
        if(ent != cache.end()){                              // (1)
            return ent->second;
        }
        else{
            cache = getUpdatedTelephoneBook();               // (2)
            return cache[name];
        }
    }
private:                                                     // (4)
    mutable std::unordered_map<std::string, int> cache = {{"grimm",123}, {"huber", 456}};
};


int main(){
    
    std::cout << std::endl;
    
    const TelephoneBook telBook;                                   // (3)
    
    std::cout << "grimm " << telBook.getNumber("grimm") << std::endl;
    
    std::cout << "schmidt " << telBook.getNumber("schmidt") << std::endl;
    
    std::cout << std::endl;
    
}
