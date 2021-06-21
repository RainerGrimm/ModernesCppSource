// makePair.cpp

#include <utility>

template<typename T1, typename T2>
std::pair<T1, T2> make_pair2(T1 t1, T2 t2) { 
    return std::pair<T1, T2>(t1, t2); 
}

int main() {
	
   auto arg{5.5};
   auto pair1 = std::make_pair(5, arg);
   auto pair2 = make_pair2(5, arg);
   auto pair3 = std::pair(5, arg);
   
}
