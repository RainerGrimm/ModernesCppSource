// forwardIterator.cpp

#include <iostream>
#include <numeric>

class Generator {
    int begin_{};
    int end_{};

 public:
    Generator(int begin, int end) : begin_{begin}, end_{end} {}

    class Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = int;
        using pointer           = int*;
        using reference         = int&;
        int value_{};
     public:
        explicit Iterator(int pos) : value_{pos} {}

        value_type operator*() const { return value_; }
        pointer operator->() { return &value_; }           

        Iterator& operator++() {                           
            ++value_;
            return *this;
        }
        Iterator operator++(int) { 
            Iterator tmp = *this; 
            ++(*this); 
            return tmp; 
        }

        friend bool operator==(const Iterator& fir, const Iterator& sec) {      
            return fir.value_ == sec.value_;
        }
        friend bool operator!=(const Iterator& fir, const Iterator& sec) {      
            return fir.value_ != sec.value_;
        }
    };

    Iterator begin() const { return Iterator{begin_}; }     
    Iterator end() const { return Iterator{end_}; }         
};

int main() {

    std::cout << '\n';
    
    Generator gen{1, 11};
    for (auto v : gen) std::cout << v << " ";

    std::cout << "\n\n";

    std::cout << "sum:  " << std::accumulate(std::begin(gen), std::end(gen), 0);

    std::cout << "\n\n";

    std::cout << "prod: " << std::accumulate(gen.begin(), gen.end(), 1, 
                                             [](int fir, int sec){ return fir * sec; });

    std::cout << "\n\n";

}