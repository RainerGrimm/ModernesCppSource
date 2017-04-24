// stringView.cpp

#include <cassert>
#include <iostream>
#include <string>

#include <string_view>

void* operator new(std::size_t count){
    std::cout << "   " << count << " bytes" << std::endl;
    return malloc(count);
}

void getString(const std::string& str){}

void getStringView(std::string_view strView){}

int main() {

    std::cout << std::endl;

    std::cout << "std::string" << std::endl;

    std::string large = "0123456789-123456789-123456789-123456789";
    std::string substr = large.substr(10);

    std::cout << std::endl;

    std::cout << "std::string_view" << std::endl;

    std::string_view largeStringView{large.c_str(), large.size()};
    largeStringView.remove_prefix(10);

    assert(substr == largeStringView);

    std::cout << std::endl;

    std::cout << "getString" << std::endl;

    getString(large);
    getString("0123456789-123456789-123456789-123456789");
    const char message []= "0123456789-123456789-123456789-123456789";
    getString(message);

    std::cout << std::endl;

    std::cout << "getStringView" << std::endl;

    getStringView(large);
    getStringView("0123456789-123456789-123456789-123456789");
    getStringView(message);

    std::cout << std::endl;

}
  


