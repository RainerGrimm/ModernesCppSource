// async.cpp

#include <iostream>
#include <future>

int main() {

    std::cout << std::endl;
    std::async([](){std::cout << "fire and forget" << std::endl;});
    std::cout << "main done " << std::endl;
}