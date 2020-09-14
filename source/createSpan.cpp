// createSpan.cpp

#include <algorithm>
#include <iostream>
#include <span>
#include <vector>

int main() {

	std::cout << std::endl;
	std::cout << std::boolalpha;

	std::vector myVec{1, 2, 3, 4, 5};
	
	std::span mySpan1{myVec};
	std::span mySpan2{myVec.data(), myVec.size()};
	
	bool spansEqual = std::equal(mySpan1.begin(), mySpan1.end(),
	                			 mySpan2.begin(), mySpan2.end());
	
	std::cout << "mySpan1 == mySpan2: " << spansEqual << std::endl;

	std::cout << std::endl;
	
}
	
	