module;

#include <iostream>

export module bar;

struct Foo {
    void writeName() {
        std::cout << "\nFoo\n";
    }

};

export struct Bar {
    Foo getFoo() {
        return Foo{};
    }
};