// iterator.cpp

#include <iostream>

class Generator {
    int begin_{};
    int end_{};

public:
    Generator(int begin, int end) : begin_{begin}, end_{end} {}

    class Iterator {
        int value_{};
    public:
        explicit Iterator(int pos) : value_{pos} {}

        int operator*() const { return value_; }

        Iterator& operator++() {
            ++value_;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return value_ != other.value_;
        }
    };

    Iterator begin() const { return Iterator{begin_}; }
    Iterator end() const { return Iterator{end_}; }
};

int main() {

   std::cout << '\n';
    
   Generator gen{100, 110};
   for (auto v : gen) std::cout << v << " ";

   std::cout << "\n\n";

}