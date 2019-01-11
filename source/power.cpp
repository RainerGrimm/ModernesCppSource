// power.cpp

#include <iostream>

int power(int m, int n){                                // (1)
    int r = 1;
    for(int k=1; k<=n; ++k) r*= m;
    return r;                                           // (3)
}

template<int m, int n>                                  // (2)
struct Power{
    static int const value = m * Power<m, n-1>::value;  // (3)
};
                          
template<int m>                                         // (2) 
struct Power<m, 0>{                                     // (2)  
    static int const value = 1;                         // (3)
};

int main(){
	
    std::cout << std::endl;	
	
    std::cout << "power(2, 10)= " << power(2, 10) << std::endl;              // (A)
	std::cout << "Power<2,10>::value= " << Power<2, 10>::value << std::endl; // (B)
	
	std::cout << std::endl;
}
