// enumUsing.cpp

#include <iostream>
#include <string_view>

enum class Color {
    red,
    green, 
    blue
};

std::string_view toString(Color col) {
  switch (col) {
    using enum Color;
    case red:   return "red";
    case green: return "green";
    case blue:  return "blue";
  }
  return "unknown";
}

int main() {

    std::cout << std::endl;
   
    std::cout << "toString(Color::red): " << toString(Color::red) << std::endl;
    
    using enum Color;
    
    std::cout << "toString(green): " << toString(green) << std::endl;
    
    std::cout << std::endl;

}    
