// reuseMemory.cpp

#include <array>
#include <cstddef>
#include <iostream>
#include <memory_resource>
#include <string>
#include <vector>

int main() {
 
    std::array<std::byte, 2000> buf;

    for (int i = 0; i < 100; ++i) {
        std::pmr::monotonic_buffer_resource pool{buf.data(), buf.size(),
                                                std::pmr::null_memory_resource()};
        std::pmr::vector<std::pmr::string> myVec{&pool};
        for (int j = 0; j < 16; ++j) {
            myVec.emplace_back("A short string");
        }
    }
}

