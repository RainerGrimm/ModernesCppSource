// typeDeductionConcepts.cpp

#include <concepts>

void foo(auto t) {}                  // (1)

void bar(std::integral auto t){}     // (2)

template <std::regular T>            // (3)
struct Class{
  Class(T){}
};

int main() {

    foo(5.5);
    bar(5);
    Class cl(true);

}