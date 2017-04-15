// fileTime.cpp

#include <iostream>
#include <chrono>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std::chrono_literals;

int main(){
    
    fs::path path = fs::current_path() / "rainer.txt";
    std::ofstream(path.c_str()); 
    auto ftime = fs::last_write_time(path);
 
    std::time_t cftime = std::chrono::system_clock::to_time_t(ftime); 
    std::cout << "Write time on server " << std::asctime(std::localtime(&cftime));
    std::cout << "Write time on server " << std::asctime(std::gmtime(&cftime)) << std::endl;
 
    fs::last_write_time(path, ftime + 2h);
    ftime = fs::last_write_time(path); 
 
    cftime = std::chrono::system_clock::to_time_t(ftime);
    std::cout << "Local time on client " << std::asctime(std::localtime(&cftime)) << std::endl;
    
    fs::remove(path);
    
}
