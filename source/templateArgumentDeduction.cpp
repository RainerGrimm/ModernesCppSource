// templateArgumentDeduction.cpp

#include <iostream>

template <typename T>
void showMe(const T& t) {
    std::cout << t << '\n';
}

template <typename T>
struct ShowMe{
    ShowMe(const T& t) {
        std::cout << t << '\n';
    }
};

int main() {
  
    std::cout << '\n';
    
    showMe(5.5);          // not showMe<double>(5.5);
    showMe(5);            // not showMe<int>(5);
    
    ShowMe(5.5);          // not ShowMe<double>(5.5);
    ShowMe(5);            // not ShowMe<int>(5);
  
    std::cout << '\n';
    
}
