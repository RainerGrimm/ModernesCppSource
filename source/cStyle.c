// cStyle.c

#include <stdio.h>

int main(){

    double sq2 = sqrt(2);                           // (1)
    
    printf("\nsizeof(\'a\'): %d\n\n", sizeof('a')); // (2)
    
    char c;
    void* pv = &c;
    int* pi = pv;                                   // (3)
    
    int class = 5;                                  // (4)
    
}
