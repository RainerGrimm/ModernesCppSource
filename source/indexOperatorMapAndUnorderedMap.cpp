// indexOperatorMapAndUnorderedMap.cpp

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

int main(){

    std::cout << std::boolalpha << std::endl;

    std::map<std::string, int> myMap;
    std::unordered_map<std::string, bool> myUnorderedMap;
	
    std::cout << "myMap[DoesNotExist]: " << myMap["DoesNotExist"] << std::endl;
	
    std::cout << "myUnorderedMap[DoesNotExist]: " << myUnorderedMap["DoesNotExist"] << std::endl;
	
}