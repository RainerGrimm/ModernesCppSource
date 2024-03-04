// formatPoint.cpp

#include <format>
#include <iostream>
#include <string>

struct Point {
    int x{2017};
    int y{2020};
    int z{2023};
};

template <>
struct std::formatter<Point> : std::formatter<std::string> {
    auto format(Point point, format_context& context) const {
        return formatter<string>::format(
               std::format("({}, {}, {})", point.x, point.y, point.y), context);
  }
};

int main() {

    std::cout << '\n';

    Point point;

    std::cout << std::format("{:*<25}", point) << '\n';        // (1)
    std::cout << std::format("{:*^25}", point) << '\n';        // (2)
    std::cout << std::format("{:*>25}", point) << '\n';        // (3)

    std::cout << '\n';

    std::cout << std::format("{} {} {}", point.x, point.y, point.z) << '\n';  // (4)
    std::cout << std::format("{0:*<10} {0:*^10} {0:*>10}", point.x) << '\n';  // (5)

    std::cout << '\n';

}