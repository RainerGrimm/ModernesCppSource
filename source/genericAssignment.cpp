// genericAssignment.cpp

#include <vector>

template <typename T, int N> // (1)
struct Point {
    Point(std::initializer_list<T> initList)
        : coord(initList)
    {
    }

    std::vector<T> coord;
};

int main()
{

    Point<int, 3> point1 { 1, 2, 3 };
    Point<int, 3> point2 { 4, 5, 6 };

    point1 = point2; // (2)

    auto doubleValue = 2.2;
    auto intValue = 2;
    doubleValue = intValue; // (3)

    Point<double, 3> point3 { 1.1, 2.2, 3.3 };
    point3 = point2; // (4)
}
