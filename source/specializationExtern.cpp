// specializationExtern.cpp

#include <cstddef>
#include <iostream>

template <typename T, std::size_t Line, std::size_t Column>  // (1)
struct Matrix;

template <typename T>                                        // (2)
struct Matrix<T, 3, 3>{
    int numberOfElements() const;
};

template <typename T>
int Matrix<T, 3, 3>::numberOfElements() const {
    return 3 * 3;
};

template <>                                                 // (3)
struct Matrix<int, 4, 4>{
    int numberOfElements() const;
};

// template <>                                              // (4)
int Matrix<int, 4, 4>::numberOfElements() const {
    return 4 * 4;
};

int main() {

    std::cout << '\n';

    Matrix<double, 3, 3> mat1;                              // (5)
    std::cout << "mat1.numberOfElements(): " << mat1.numberOfElements() << '\n';

    Matrix<int, 4, 4> mat2;                                 // (6)
    std::cout << "mat2.numberOfElements(): " << mat2.numberOfElements() << '\n';

    std::cout << '\n';
    
}

