// callable.cpp

#include <cmath>
#include <functional>
#include <iostream>
#include <map>

double add(double a, double b){
	return a + b;
}

struct Sub{
	double operator()(double a, double b){
		return a - b;
	}
};

double multThree(double a, double b, double c){
	return a * b * c;
}

int main(){
    
    using namespace std::placeholders;

    std::cout << std::endl;

    std::map<const char , std::function<double(double, double)>> dispTable{  // (1)
        {'+', add },                                         // (2)
        {'-', Sub() },                                       // (3)
        {'*', std::bind(multThree, 1, _1, _2) },             // (4)
        {'/',[](double a, double b){ return a / b; }}};      // (5)

    std::cout << "3.5 + 4.5 = " << dispTable['+'](3.5, 4.5) << std::endl;
    std::cout << "3.5 - 4.5 = " << dispTable['-'](3.5, 4.5) << std::endl;
    std::cout << "3.5 * 4.5 = " << dispTable['*'](3.5, 4.5) << std::endl;
    std::cout << "3.5 / 4.5 = " << dispTable['/'](3.5, 4.5) << std::endl;

    std::cout << std::endl;

}
