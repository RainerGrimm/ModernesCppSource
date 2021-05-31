// classTemplatePartial.cpp

#include <iostream>
#include <vector>

template <typename T>
class Matrix{
 public:
    explicit Matrix(std::initializer_list<T> inList): data(inList) {}
    void printAll() const {
        for (const auto& d: data) std::cout << d << " ";
    }
private:
    std::vector<T> data;
};

int main() {

    std::cout << '\n';

    const Matrix<int> myMatrix1({1, 2, 3, 4, 5});
    myMatrix1.printAll();

    std::cout << "\n\n";

    const Matrix<int> myMatrix2({10, 11, 12, 13});
    myMatrix2.printAll();

    std::cout << "\n\n";

    const Matrix<Matrix<int>> myMatrix3({myMatrix1, myMatrix2});
    // myMatrix3.printAll(); ERROR

}