#include <iostream>
#include <string>

struct Shape {
  virtual ~Shape() = default;

  virtual std::string GetName() const = 0;
};

struct Circle : Shape {
  void Resize(float factor) { radius *= factor; }

  std::string GetName() const override {
    return std::string("A circle of radius ") + std::to_string(radius);
  }

  float radius = 10.0f;
};

struct ColoredShape : Shape {
  ColoredShape(const std::string& color, Shape* shape)
      : color(color), shape(shape) {}

  std::string GetName() const override {
    return shape->GetName() + " which is colored " + color + ".";
  }

  std::string color;
  Shape* shape;
};

int main() {

  std::cout << '\n';

  Circle circle;
  ColoredShape colored_shape("red", &circle);
  std::cout << colored_shape.GetName() << '\n';

  std::cout << '\n';

}