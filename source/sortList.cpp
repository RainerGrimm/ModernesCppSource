// sortList.cpp

#include <algorithm>
#include <list>

int main(){
    
    std::list<int> myList{1, 10, 3, 2, 5};
    
    std::sort(myList.begin(), myList.end());
    
}
