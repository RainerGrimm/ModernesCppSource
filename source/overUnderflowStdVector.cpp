// overUnderflowStdVector.cpp

#include <iostream>
#include <vector>

int main()
{

    std::vector<int> a { 1 };
    int n {};

    while (true) {
        if (!(n % 100)) {
            std::cout << "a[" << n << "] = " << a[n] << ", a[" << -n << "] = " << a[-n] << "\n";
        }
        a[n] = n;
        a[-n] = -n;
        ++n;
    }
}
