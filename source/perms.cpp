// perms.cpp

#include <fstream>
#include <bitset>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
 
void printPerms(fs::perms perm){
  std::cout << ((perm & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
            << ((perm & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
            << ((perm & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
            << ((perm & fs::perms::group_read) != fs::perms::none ? "r" : "-")
            << ((perm & fs::perms::group_write) != fs::perms::none ? "w" : "-")
            << ((perm & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
            << ((perm & fs::perms::others_read) != fs::perms::none ? "r" : "-")
            << ((perm & fs::perms::others_write) != fs::perms::none ? "w" : "-")
            << ((perm & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
            << std::endl;
}


int main(){
  
    std::ofstream("rainer.txt");
 
    std::cout << "Initial file permissions for a file: ";
    printPerms(fs::status("rainer.txt").permissions());
 
    fs::permissions("rainer.txt", fs::perms::add_perms |
                            fs::perms::owner_all | fs::perms::group_all);
    std::cout << "Adding all bits to owner and group:  ";
    printPerms(fs::status("rainer.txt").permissions());
    
    fs::permissions("rainer.txt", fs::perms::remove_perms | 
                           fs::perms::owner_write | fs::perms::group_write | fs::perms::others_write);
    std::cout << "Removing the write bits for all:     ";
    printPerms(fs::status("rainer.txt").permissions());
 
    fs::remove("rainer.txt");
    
}
