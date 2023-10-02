// nullMemoryResource.cpp

#include <array>
#include <cstddef>
#include <iostream> 
#include <memory_resource>
#include <string>
#include <vector>

int main() {

    std::cout << '\n';
 
    std::array<std::byte, 2000> buf;
    std::pmr::monotonic_buffer_resource pool{buf.data(), buf.size(),
                                           std::pmr::null_memory_resource()};
    std::pmr::vector<std::pmr::string> myVec{&pool};
    try {
        for (int i = 0; i < 100; ++i) {
            std::cerr << i << " ";
            myVec.emplace_back("A short string");
        }
    }
    catch (const std::bad_alloc& e) {
        std::cerr << '\n' << e.what() << '\n';
    }
    
    std::cout << '\n';
    
}

