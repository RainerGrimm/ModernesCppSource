// arrayClassTemplate.cpp

#include <cstddef>                     // (1)
#include <iostream>
#include <string>

template <typename T, std::size_t N>   // (2)
class Array{

 public:
    int getSize() const {
        return N;
    }

private:
    T elem[N];
};

int main() {

    std::cout << '\n';

    Array<int, 100> intArr;             // (3)
    std::cout << "intArr.getSize(): " << intArr.getSize() << '\n';

    Array<std::string, 5> strArr;       // (4)
    std::cout << "strArr.getSize(): " << strArr.getSize() << '\n';

    Array<Array<int, 3>, 25> intArrArr; // (5)
    std::cout << "intArrArr.getSize(): " << intArrArr.getSize() << '\n';

    std::cout << '\n';

}