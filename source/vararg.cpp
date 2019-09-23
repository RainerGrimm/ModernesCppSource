// vararg.cpp

#include <iostream>
#include <cstdarg>

int sum(int num, ... ){
  
    int sum{};
      
    va_list argPointer;
    va_start(argPointer, num );
    for( int i = 0; i < num; i++ )
        sum += va_arg(argPointer, int );
    va_end(argPointer);
      
    return sum;
}
 
int main(){
    
    std::cout << "sum(1, 5): " << sum(1, 5) << std::endl;
    std::cout << "sum(3, 1, 2, 3): " << sum(3, 1, 2, 3) << std::endl;
    std::cout << "sum(3, 1, 2, 3, 4): " << sum(3, 1, 2, 3, 4)  << std::endl; // (1)
    std::cout << "sum(3, 1, 2, 3.5): " << sum(3, 1, 2, 3.5) << std::endl;    // (2)

}