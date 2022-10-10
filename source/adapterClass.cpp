// adapterClass.cpp

#include <iostream>

typedef int Coordinate;
typedef int Dimension;

class Rectangle {
public:
    virtual void draw() = 0;
    virtual ~Rectangle() = default;
};

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


class RectangleAdapter : public Rectangle, private LegacyRectangle {
 public:
    RectangleAdapter(Coordinate x, Coordinate y, Dimension w, Dimension h) : LegacyRectangle(x, y, x + w, y + h) {
        std::cout << "RectangleAdapter: create.  (" << x << "," << y 
                  << "), width = " << w << ", height = " << h << '\n';
    }

    void draw() override {
        oldDraw();
        std::cout << "RectangleAdapter: draw." << '\n';
    }
};

int main() {

    std::cout << '\n';

    Rectangle* r = new RectangleAdapter(120, 200, 60, 40);
    r->draw();

    delete r;

    std::cout << '\n';
    
}
