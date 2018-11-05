// sumUpLambda.cpp

#include <algorithm>
#include <iostream>
#include <vector>

int main(){
	
	std::cout << std::endl;

    std::vector<int> intVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::for_each(intVec.begin(), intVec.end(),
	            [sum = 0](int i) mutable {
				    sum += i; 
					std::cout << sum << std::endl;
				});
    
    std::cout << "\n";

}