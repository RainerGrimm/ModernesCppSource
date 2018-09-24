// conversionOperator.cpp

#include <iostream>
#include <string>

struct MyHouse{
    MyHouse() = default;
    MyHouse(const std::string& fam): family(fam){}
	
    operator bool(){ return !family.empty(); }              
	
    std::string family = "";
};

void needInt(int i){
    std::cout << "int: " << i << std::endl;
}

int main(){
	
    std::cout << std::boolalpha << std::endl;
	
    MyHouse firstHouse;
    if (!firstHouse){                                        
        std::cout << "The firstHouse is still empty." << std::endl;
    };
	
    MyHouse secondHouse("grimm");                               
    if (secondHouse){
        std::cout << "Family grimm lives in secondHouse." << std::endl;
    }
	
	std::cout << std::endl;
	
	needInt(firstHouse);
	needInt(secondHouse);
	
	std::cout << std::endl;
	
}