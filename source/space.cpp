// space.cpp

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(){
    
    fs::space_info root = fs::space("/");
    fs::space_info usr = fs::space("/usr");
 
    std::cout << "        Capacity       Free      Available\n"
              << "/    " << root.capacity << "   "
              << root.free << "   " << root.available << "\n"   
              << "usr  "  << usr.capacity << "   "
              << usr.free <<  "   " << usr.available;
              
}
