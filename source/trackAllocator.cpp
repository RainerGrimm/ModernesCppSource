// trackAllocator.cpp

#include <array>
#include <cstdlib>
#include <format>
#include <iostream>
#include <memory_resource>
#include <vector>

class TrackAllocator : public std::pmr::memory_resource {
    void* do_allocate(std::size_t bytes, std::size_t alignment) override {
        void* p = std::pmr::new_delete_resource()->allocate(bytes, alignment);
        std::cout << std::format("  do_allocate: {:6} bytes at {}\n", bytes, p);
        return p;
    }
 
    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override {
        std::cout << std::format("  do_deallocate: {:4} bytes at {}\n", bytes, p);
        return std::pmr::new_delete_resource()->deallocate(p, bytes, alignment);
    }
 
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return std::pmr::new_delete_resource()->is_equal(other);
    }
};


int main() {

    std::cout << '\n';

    TrackAllocator trackAllocator;
    std::pmr::set_default_resource(&trackAllocator);

    std::cout << "myVec1\n";

    std::array<std::byte, 200> buf1;
    std::pmr::monotonic_buffer_resource pool1{buf1.data(), buf1.size()};
    std::pmr::vector<int> myVec1{&pool1};
    for (int i = 0; i < 5; ++i) {
        myVec1.push_back(i);
    }

    std::cout << "myVec2\n";

    char buf2[200] = {}; 
    std::pmr::monotonic_buffer_resource pool2{std::data(buf2), std::size(buf2)};
    std::pmr::vector<int> myVec2{&pool2};
    for (int i = 0; i < 200; ++i) {
        myVec2.push_back(i);
    }

    std::cout << '\n';

}