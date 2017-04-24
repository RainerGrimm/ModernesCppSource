// substr.cpp

#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include <string_view>

static const int count = 30;
static const int access = 10000000;

int main(){

    std::cout << std::endl;

    std::ifstream inFile("grimm.txt");

    std::stringstream strStream;
    strStream <<  inFile.rdbuf();
    std::string grimmsTales = strStream.str();

    size_t size = grimmsTales.size();

    std::cout << "Grimms' Fairy Tales size: " << size << std::endl;
    std::cout << std::endl;

    // random values
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<> uniformDist(0, size - count - 2);
    std::vector<int> randValues;
    for (auto i = 0; i <  access; ++i) randValues.push_back(uniformDist(engine));

    auto start = std::chrono::steady_clock::now();
    for (auto i = 0; i  < access; ++i ) {
        grimmsTales.substr(randValues[i], count);
    }
    std::chrono::duration<double> durString= std::chrono::steady_clock::now() - start;
    std::cout << "std::string::substr:      " << durString.count() << " seconds" << std::endl;

    std::string_view grimmsTalesView{grimmsTales.c_str(), size};
    start = std::chrono::steady_clock::now();
    for (auto i = 0; i  < access; ++i ) {
        grimmsTalesView.substr(randValues[i], count);
    }
    std::chrono::duration<double> durStringView= std::chrono::steady_clock::now() - start;
    std::cout << "std::string_view::substr: " << durStringView.count() << " seconds" << std::endl;

    std::cout << std::endl;

    std::cout << "durString.count()/durStringView.count(): " << durString.count()/durStringView.count() << std::endl;

    std::cout << std::endl;

}