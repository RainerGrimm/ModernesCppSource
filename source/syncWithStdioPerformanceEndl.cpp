// syncWithStdioPerformanceEndl.cpp

#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

constexpr int iterations = 500; // (1)

std::ifstream openFile(const std::string& myFile)
{

    std::ifstream file(myFile, std::ios::in);
    if (!file) {
        std::cerr << "Can't open file " + myFile + "!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return file;
}

std::string readFile(std::ifstream file)
{

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

template <typename End>
auto writeToConsole(const std::string& fileContent, End end)
{

    auto start = std::chrono::steady_clock::now();
    for (auto c : fileContent)
        std::cout << c << end; // (3)
    std::chrono::duration<double> dur = std::chrono::steady_clock::now() - start;
    return dur;
}

template <typename Function>
auto measureTime(std::size_t iter, Function&& f)
{
    std::chrono::duration<double> dur {};
    for (int i = 0; i < iter; ++i) {
        dur += f();
    }
    return dur / iter;
}

int main(int argc, char* argv[])
{

    std::cout << std::endl;

    // get the filename
    std::string myFile;
    if (argc == 2) {
        myFile = argv[1];
    } else {
        std::cerr << "Filename missing !" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ifstream file = openFile(myFile);

    std::string fileContent = readFile(std::move(file));

    auto averageWithFlush = measureTime(iterations,
        [&fileContent] { return writeToConsole(fileContent, std::endl<char, std::char_traits<char>>); }); // (2)
    auto averageWithoutFlush = measureTime(iterations, [&fileContent] { return writeToConsole(fileContent, '\n'); }); // (3)

    std::cout << std::endl;
    std::cout << "With flush(std::endl) " << averageWithFlush.count() << " seconds" << std::endl;
    std::cout << "Without flush(\\n): " << averageWithoutFlush.count() << " seconds" << std::endl;
    std::cout << "With Flush/Without Flush: " << averageWithFlush / averageWithoutFlush << std::endl;

    std::cout << std::endl;
}
