// stacktrace1.cpp

#include <iostream>
#include <stacktrace>

 
void func3() {
    std::cout << std::stacktrace::current()  << '\n';
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