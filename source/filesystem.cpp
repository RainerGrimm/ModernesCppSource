// filesystem.cpp

#include <fstream>
#include <iostream>
#include <string>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
 
int main(){

    std::cout << "Current path: " << fs::current_path() << std::endl;

    std::string dir= "sandbox/a/b";
    fs::create_directories(dir);

    std::ofstream("sandbox/file1.txt");
    fs::path symPath= fs::current_path() /=  "sandbox";
    symPath /= "syma";
    fs::create_symlink("a", "symPath");
    
    std::cout << "fs::is_directory(dir): " << fs::is_directory(dir) << std::endl;
    std::cout << "fs::exists(symPath): "  << fs::exists(symPath) << std::endl;
    std::cout << "fs::symlink(symPath): " << fs::is_symlink(symPath) << std::endl;
    

    for(auto& p: fs::recursive_directory_iterator("sandbox"))
        std::cout << p << std::endl;
    // fs::remove_all("sandbox");
    
}
