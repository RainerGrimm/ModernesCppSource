// lambdaCpp11.cpp

#include <algorithm>
#include <iostream>
#include <string>
#include <array>
#include <vector>

template <typename Cont, typename Pred>
void sortDescending(Cont& cont, Pred pred){
    std::sort(cont.begin(), cont.end(), pred);
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
    
    sortDescending(myArray, [](int fir, int sec){ return fir > sec; });           // (1)
    sortDescending(myVector, [](double fir, double sec){ return fir > sec; });    // (2)
    sortDescending(myVector2, [](const std::string& fir, const std::string& sec){ // (3)
       return fir > sec; 
    });

    printMe(myArray);
    printMe(myVector);
    printMe(myVector2);
    
    std::cout << std::endl;
    
}
