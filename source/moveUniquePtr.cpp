// moveUniquePtr.cpp

#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

void takeUniquePtr(std::unique_ptr<int> uniqPtr)
{ // (1)
    std::cout << "*uniqPtr: " << *uniqPtr << std::endl;
}

int main()
{

    std::cout << std::endl;

    auto uniqPtr1 = std::make_unique<int>(2014);

    takeUniquePtr(std::move(uniqPtr1));

    auto uniqPtr2 = std::make_unique<int>(2017);
    auto uniqPtr3 = std::make_unique<int>(2020);
    auto uniqPtr4 = std::make_unique<int>(2023);

    std::vector<std::unique_ptr<int>> vecUniqPtr;
    vecUniqPtr.push_back(std::move(uniqPtr2)); // (2)
    vecUniqPtr.push_back(std::move(uniqPtr3)); // (2)
    vecUniqPtr.push_back(std::move(uniqPtr4)); // (2)

    std::cout << std::endl;

    std::for_each(vecUniqPtr.begin(), vecUniqPtr.end(), // (3)
        [](std::unique_ptr<int>& uniqPtr) { std::cout << *uniqPtr << std::endl; });

    std::cout << std::endl;
}
