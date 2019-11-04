// aggregateInitialisation.cpp

#include <iostream>

struct Point2D{
    int x;
    int y;
};

class Point3D{
public:
    int x;
    int y;
    int z;
};

int main(){
    
    std::cout << std::endl;
    
    Point2D point2D {1, 2};
    Point3D point3D {1, 2, 3};

    std::cout << "point2D: " << point2D.x << " " << point2D.y << std::endl;
    std::cout << "point3D: " << point3D.x << " " << point3D.y << " " << point3D.z << std::endl;
    
    std::cout << std::endl;

}
