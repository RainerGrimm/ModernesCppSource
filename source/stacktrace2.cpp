// stacktrace2.cpp

#include <iostream>
#include <stacktrace>

 
void func3() {
    auto stacktrace = std::stacktrace::current();
    for (const auto& entry: stacktrace) {
        std::cout << "Description: " << entry.description() << '\n';
        std::cout << "file: " << entry.source_file() << " and line: " << entry.source_line() <<'\n';
        std::cout << '\n';
    }
}
 
void func2() {
    func3();
}
 
void func1() {
    func2(); 
}
 
int main() {
    func1();
}