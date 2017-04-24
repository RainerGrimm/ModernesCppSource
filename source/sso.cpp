// sso.cpp

#include <iostream>
#include <string>

void* operator new(std::size_t count){
    std::cout << "   " << count << " bytes" << std::endl;
    return malloc(count);
}

void getString(const std::string& str){}

int main() {

    std::cout << std::endl;

    std::cout << "std::string" << std::endl;

    std::string small = "0123456789";
    std::string substr = small.substr(5);
    std::cout << "   " << substr << std::endl;

    std::cout << std::endl;

    std::cout << "getString" << std::endl;

    getString(small);
    getString("0123456789");
    const char message []= "0123456789";
    getString(message);

    std::cout << std::endl;

}
  


