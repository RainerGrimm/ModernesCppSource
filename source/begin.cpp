// begin.cpp

#include <cstddef>
#include <iostream>
#include <ranges>

struct ContainerFree {                                        // (1)
    ContainerFree(std::size_t len): len_(len), data_(new int[len]){}
    size_t len_;
    int* data_;
};
int* begin(const ContainerFree& conFree) {                   // (2)
    return conFree.data_;
}

struct ContainerMember {                                      // (3)
    ContainerMember(std::size_t len): len_(len), data_(new int[len]){}
    int* begin() const {                                      // (4)
        return data_;
    }
    size_t len_;
    int* data_;
};

void callBeginFree(const auto& cont) {                         // (5)
    begin(cont);
}

void callBeginMember(const auto& cont) {                       // (6)
    cont.begin();
}
 
int main() {

    const ContainerFree contFree(2020);
    const ContainerMember contMemb(2023);

    callBeginFree(contFree);                                 
    callBeginMember(contMemb);

    callBeginFree(contMemb);                                  // (7)
    callBeginMember(contFree);                                // (8)
   
}