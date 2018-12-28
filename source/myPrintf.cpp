// myPrintf.cpp

#include <iostream>
 
void myPrintf(const char* format){                           // (3)
    std::cout << format;
}
 
template<typename T, typename ... Args>
void myPrintf(const char* format, T value, Args ... args){   // (4)
    for ( ; *format != '\0'; format++ ) {                    // (5)
        if ( *format == '%' ) {                               
           std::cout << value;
           myPrintf(format + 1, args ... );                  // (6)
           return;
        }
        std::cout << *format;
    }
}
 
int main(){
    
    myPrintf("\n");                                          // (1)
    
    myPrintf("% world% %\n", "Hello", '!', 2011);            // (2)
    
    myPrintf("\n");                                          
    
}
