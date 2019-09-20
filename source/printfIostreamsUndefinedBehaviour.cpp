// printfIostreamsUndefinedBehaviour.cpp

#include <cstdio>

#include <iostream>

int main()
{

    printf("\n");

    printf("2011: %d\n", 2011);
    printf("3.1416: %d\n", 3.1416);
    printf("\"2011\": %d\n", "2011");
    // printf("%s\n",2011);    // segmentation fault

    std::cout << std::endl;
    std::cout << "2011: " << 2011 << std::endl;
    std::cout << "3.146: " << 3.1416 << std::endl;
    std::cout << "\"2011\": "
              << "2011" << std::endl;

    std::cout << std::endl;
}
