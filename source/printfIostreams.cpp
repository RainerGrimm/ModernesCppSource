// printfIostreams.cpp

#include <cstdio>

#include <iomanip>
#include <iostream>
 
int main(){
    
    printf("\n");
    printf("Characters: %c %c \n", 'a', 65);
    printf("Decimals: %d %ld\n", 2011, 650000L);
    printf("Preceding with blanks: %10d \n", 2011);
    printf("Preceding with zeros: %010d \n", 2011);
    printf("Doubles: %4.2f %E \n", 3.1416, 3.1416);
    printf("%s \n", "From C to C++");
    
    std::cout << std::endl;
    std::cout << "Characters: " << 'a' << " " <<  static_cast<char>(65) << std::endl;  
    std::cout << "Decimals: " << 2011 << " " << 650000L << std::endl;
    std::cout << "Preceding with blanks: " << std::setw(10) << 2011 << std::endl;
    std::cout << "Preceding with zeros: " << std::setfill('0') << std::setw(10) << 20011 << std::endl;
    std::cout << "Doubles: " << std::setprecision(3) << 3.1416 << " " 
                             << std::setprecision(6) << std::scientific <<  3.1416 << std::endl;
    std::cout << "From C to C++" << std::endl;
  
    std::cout << std::endl;
    
}

