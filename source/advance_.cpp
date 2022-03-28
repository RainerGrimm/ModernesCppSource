// advance_.cpp

#include <iterator>
#include <forward_list>
#include <list>
#include <vector>
#include <iostream>

template <typename InputIterator, typename Distance>                    // (7)
void advance_impl(InputIterator& i, Distance n, std::input_iterator_tag) {
	std::cout << "InputIterator used" << '\n'; 
    while (n--) ++i;
}

template <typename BidirectionalIterator, typename Distance>            // (6)  
void advance_impl(BidirectionalIterator& i, Distance n, std::bidirectional_iterator_tag) {
	std::cout << "BidirectionalIterator used" << '\n';
    if (n >= 0) 
        while (n--) ++i;
    else 
        while (n++) --i;
}

template <typename RandomAccessIterator, typename Distance>             // (5)
void advance_impl(RandomAccessIterator& i, Distance n, std::random_access_iterator_tag) {
	std::cout << "RandomAccessIterator used" << '\n';
    i += n;
}

template <typename InputIterator, typename Distance>                    // (4)
void advance_(InputIterator& i, Distance n) {
    typename std::iterator_traits<InputIterator>::iterator_category category;    
    advance_impl(i, n, category);                                               
}
  
int main(){
    
    std::cout << '\n';
    
    std::vector<int> myVec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};               // (1)
    auto myVecIt = myVec.begin();                                               
    std::cout << "*myVecIt: " << *myVecIt << '\n';
    advance_(myVecIt, 5);
    std::cout << "*myVecIt: " << *myVecIt << '\n';
    
    std::cout << '\n';
    
    std::list<int> myList{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};                // (2)
    auto myListIt = myList.begin();                                             
    std::cout << "*myListIt: " << *myListIt << '\n';
    advance_(myListIt, 5);
    std::cout << "*myListIt: " << *myListIt << '\n';
    
    std::cout << '\n';
    
    std::forward_list<int> myForwardList{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // (3)
    auto myForwardListIt = myForwardList.begin();                               
    std::cout << "*myForwardListIt: " << *myForwardListIt << '\n';
    advance_(myForwardListIt, 5);
    std::cout << "*myForwardListIt: " << *myForwardListIt << '\n';
    
    std::cout << '\n';
    
}
