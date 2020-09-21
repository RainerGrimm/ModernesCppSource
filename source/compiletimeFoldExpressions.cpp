// compiletimeFoldExpressions.cpp

#include <iostream>

template<typename... Args>
auto sum(const Args&... args)
{
  return (args + ...);
}

template<typename... Args>
auto product(const Args&... args)
{
  return (args * ...);
}

int main() {

    std::cout << std::endl;

    std::cout << "sum(1, 2, 3, 4, 5): " << sum(1, 2, 3, 4, 5) << std::endl;
    std::cout << "product(1, 2, 3, 4, 5): " << product(1, 2, 3, 4, 5) << std::endl;

    std::cout << std::endl;

}
