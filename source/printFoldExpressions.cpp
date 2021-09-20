// printFoldExpressions.cpp

#include <iostream>
#include <string>

template<typename ... Args>
void printMe(Args&& ... args) {
    (std::cout <<  ... <<  std::forward<Args>(args)) << '\n';
}

int main() {

    std::cout << '\n';

    std::cout << std::boolalpha;

    printMe();
    printMe("Rainer ", "Grimm");
    printMe(true, " ", "+", " ",false, " = ", true + false);
    
    std::cout << '\n';

}