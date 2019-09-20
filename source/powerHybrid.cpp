// powerHybrid.cpp

#include <iostream>

template <int n>
int power(int m)
{
    return m * power<n - 1>(m);
}

template <>
int power<1>(int m)
{
    return m;
}

template <>
int power<0>(int m)
{
    return 1;
}

int main()
{

    std::cout << std::endl;

    std::cout << "power<10>(2): " << power<10>(2) << std::endl; // (1)

    std::cout << std::endl;

    auto power2 = power<2>; // (2)

    for (int i = 0; i <= 10; ++i) {
        std::cout << "power2(" << i << ")= "
                  << power2(i) << std::endl; // (3)
    }

    std::cout << std::endl;
}
