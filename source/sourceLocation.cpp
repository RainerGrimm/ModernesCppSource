// sourceLocation.cpp
// from cppreference.com

#include <iostream>
#include <string_view>
#include <source_location>
 
void log(std::string_view message,
         const std::source_location& location = std::source_location::current())
{
    std::cout << "info:"
              << location.file_name() << ':'
              << location.line() << ' '
              << message << '\n';
}
 
int main()
{
    log("Hello world!");
}