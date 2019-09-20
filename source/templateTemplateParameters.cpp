// templateTemplateParameters.cpp

#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T, template <typename, typename> class Cont> // (1)
class Matrix {
public:
    explicit Matrix(std::initializer_list<T> inList)
        : data(inList)
    { // (2)
        for (auto d : data)
            std::cout << d << " ";
    }
    int getSize() const
    {
        return data.size();
    }

private:
    Cont<T, std::allocator<T>> data; // (3)
};

int main()
{

    std::cout << std::endl;

    // (4)
    Matrix<int, std::vector> myIntVec { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::cout << std::endl;
    std::cout << "myIntVec.getSize(): " << myIntVec.getSize() << std::endl;

    std::cout << std::endl;

    // (5)
    Matrix<double, std::vector> myDoubleVec { 1.1, 2.2, 3.3, 4.4, 5.5 };
    std::cout << std::endl;
    std::cout << "myDoubleVec.getSize(): " << myDoubleVec.getSize() << std::endl;

    std::cout << std::endl;
    // (6)
    Matrix<std::string, std::list> myStringList { "one", "two", "three", "four" };
    std::cout << std::endl;
    std::cout << "myStringList.getSize(): " << myStringList.getSize() << std::endl;

    std::cout << std::endl;
}
