#include <utility>

import bar;

int main() {

    Bar b;
    // Foo f;                 
    auto f = b.getFoo();   
    f.writeName();

    using FooAlias = decltype(std::declval<Bar>().getFoo()); 
    FooAlias f2;
    f2.writeName();

}