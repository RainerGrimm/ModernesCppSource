// genericAssignment2.cpp

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T, int N>
struct Point{

    Point(std::initializer_list<T> initList): coord(initList){}

    template <typename T2>                        
    Point<T, N>& operator=(const Point<T2, N>& point){     // (1)
        static_assert(std::is_convertible<T2, T>::value, 
                      "Cannot convert source type to destination type!");
        coord.clear();
        coord.insert(coord.begin(), point.coord.begin(), point.coord.end());
        return *this;
    }
    
    std::vector<T> coord;
    
};


int main(){

  Point<double, 3> point1{1.1, 2.2, 3.3};
  Point<int, 3> point2{1, 2, 3};
  
  Point<int, 2> point3{1, 2};
  Point<std::string, 3> point4{"Only", "a", "test"};

  point1 = point2;                                        // (2)
  
  // point2 = point3;                                     // (3)
  // point2 = point4;                                     // (4)

}
