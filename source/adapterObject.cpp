// adapterObject.cpp

#include <iostream>

typedef int Coordinate;
typedef int Dimension;

class LegacyRectangle {
 public:
    LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2) : x1_(x1), y1_(y1), x2_(x2), y2_(y2){
        std::cout << "LegacyRectangle:  create.  (" << x1_ << "," << y1_ << ") => ("
                  << x2_ << "," << y2_ << ")" << '\n';
    }

    void oldDraw() {
        std::cout << "LegacyRectangle:  oldDraw.  (" << x1_ << "," << y1_ 
                  << ") => (" << x2_ << "," << y2_ << ")" << '\n';
    }

 private:
    Coordinate x1_;
    Coordinate y1_;
    Coordinate x2_;
    Coordinate y2_;
};

class RectangleAdapter {
 public:
    RectangleAdapter(Coordinate x, Coordinate y, Dimension w, Dimension h) : legacyRectangle{LegacyRectangle(x, y, x + w, y + h)} {
        std::cout << "RectangleAdapter: create.  (" << x << "," << y 
                  << "), width = " << w << ", height = " << h << '\n';
    }

    void draw() {
        legacyRectangle.oldDraw();
        std::cout << "RectangleAdapter: draw." << '\n';
    }
 private:
     LegacyRectangle legacyRectangle;
};

int main() {

    std::cout << '\n';

    RectangleAdapter r(120, 200, 60, 40);
    r.draw();

    std::cout << '\n';
}