// typeErasureOO.cpp

#include <iostream>
#include <string>
#include <vector>

struct BaseClass{                                     // (2)
	virtual std::string getName() const = 0;
};

struct Bar: BaseClass{
	std::string getName() const override {
	    return "Bar";
	}
};

struct Foo: BaseClass{
	std::string getName() const override{
	    return "Foo";
	}
};

void printName(std::vector<const BaseClass*> vec){    // (3)
    for (auto v: vec) std::cout << v->getName() << std::endl;
}


int main(){
	
	std::cout << std::endl;
	
	Foo foo;
	Bar bar; 
	
	std::vector<const BaseClass*> vec{&foo, &bar};    // (1)
	
	printName(vec);
	
	std::cout << std::endl;

}