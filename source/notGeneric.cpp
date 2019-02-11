// notGeneric.cpp

#include <deque>
#include <list>
#include <vector>

template <typename Cont>
void justIterate(const Cont& cont){
    const auto itEnd = cont.end();
    for (auto it = cont.begin(); it < itEnd; ++it) {   // (1)
        // do something
    }
}
    
int main(){
    
    std::vector<int> vecInt{1, 2, 3, 4, 5};
    justIterate(vecInt);                                // (2)
    
    std::deque<int> deqInt{1, 2, 3, 4, 5};
    justIterate(deqInt);                                // (3)
    
    std::list<int> listInt{1, 2, 3, 4, 5};
    justIterate(listInt);                               // (4)
    
}
