// lambdaCpp14.cpp

#include <algorithm>
#include <iostream>
#include <string>
#include <array>
#include <vector>

template <typename Cont>
void sortDescending(Cont& cont){
    std::sort(cont.begin(), cont.end(), [](auto fir, auto sec){   // (1)
        return fir > sec; 
    });
}

template <typename Cont>
void printMe(const Cont& cont){
    for (auto c: cont) std::cout << c << " ";
    std::cout << std::endl;
}

int main(){

    std:: cout << std::endl;
    
    std::array<int, 10> myArray{5, -10, 3, 2, 7, 8, 9, -4, 3, 4};
    std::vector<double> myVector{5.1, -10.5, 3.1, 2.0, 7.2, 8.3};
    std::vector<std::string> myVector2{"Only", "for", "testing", "purpose"};
    
    sortDescending(myArray);      // (2)
    sortDescending(myVector);     // (2)
    sortDescending(myVector2);    // (2)

    printMe(myArray);
    printMe(myVector);
    printMe(myVector2);
    
    std::cout << std::endl;
    
}
