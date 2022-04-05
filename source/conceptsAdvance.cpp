// conceptsAdvance.cpp

#include <concepts>
#include <iostream>
#include <forward_list>
#include <list>
#include <vector>

template<std::input_iterator I>
void advance_(I& i, int n){
    std::cout << "InputIterator used" << '\n';
    if (n >= 0) { while (n--) ++it; }
}

template<std::bidirectional_iterator I>
void advance_(I& i, int n){
    std::cout << "BidirectionalIterator used" << '\n';
    if (n >= 0) 
        while (n--) ++i;
    else 
        while (n++) --i;
}

template<std::random_access_iterator I>
void advance_(I& i, int n){
    std::cout << "RandomAccessIterator used" << '\n';
    i += n;  
}

int main() {

    std::cout << '\n';

    std::forward_list forwList{1, 2, 3};
    std::forward_list<int>::iterator itFor = forwList.begin();
    advance_(itFor, 2);

    std::list li{1, 2, 3};
    std::list<int>::iterator itBi = li.begin();
    advance_(itBi, 2);

    std::vector vec{1, 2, 3};
    std::vector<int>::iterator itRa = vec.begin();
    advance_(itRa, 2);

    std::cout << '\n';
}