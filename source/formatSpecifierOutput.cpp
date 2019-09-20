// formatSpecifierOutput.cpp

#include <iomanip>
#include <iostream>

int main()
{

    std::cout << std::endl;

    std::cout << "std::setw, std::setfill and std::left, right and internal: " << std::endl;

    std::cout.fill('#');
    std::cout << -12345 << std::endl;
    std::cout << std::setw(10) << -12345 << std::endl;
    std::cout << std::setw(10) << std::left << -12345 << std::endl;
    std::cout << std::setw(10) << std::right << -12345 << std::endl;
    std::cout << std::setw(10) << std::internal << -12345 << std::endl;

    std::cout << std::endl;

    std::cout << "std::showpos:" << std::endl;

    std::cout << 2011 << std::endl;
    std::cout << std::showpos << 2011 << std::endl;

    std::cout << std::noshowpos << std::endl;

    std::cout << "std::uppercase: " << std::endl;
    std::cout << 12345678.9 << std::endl;
    std::cout << std::uppercase << 12345678.9 << std::endl;

    std::cout << std::nouppercase << std::endl;

    std::cout << "std::showbase and std::oct, dec and hex: " << std::endl;
    std::cout << 2011 << std::endl;
    std::cout << std::oct << 2011 << std::endl;
    std::cout << std::hex << 2011 << std::endl;

    std::cout << std::endl;

    std::cout << std::showbase;
    std::cout << std::dec << 2011 << std::endl;
    std::cout << std::oct << 2011 << std::endl;
    std::cout << std::hex << 2011 << std::endl;

    std::cout << std::dec << std::endl;

    std::cout << "std::setprecision, std::fixed and std::scientific: " << std::endl;

    std::cout << 123.456789 << std::endl;
    std::cout << std::fixed << std::endl;
    std::cout << std::setprecision(3) << 123.456789 << std::endl;
    std::cout << std::setprecision(4) << 123.456789 << std::endl;
    std::cout << std::setprecision(5) << 123.456789 << std::endl;
    std::cout << std::setprecision(6) << 123.456789 << std::endl;
    std::cout << std::setprecision(7) << 123.456789 << std::endl;
    std::cout << std::setprecision(8) << 123.456789 << std::endl;
    std::cout << std::setprecision(9) << 123.456789 << std::endl;

    std::cout << std::endl;
    std::cout << std::setprecision(6) << 123.456789 << std::endl;
    std::cout << std::scientific << std::endl;
    std::cout << std::setprecision(6) << 123.456789 << std::endl;
    std::cout << std::setprecision(3) << 123.456789 << std::endl;
    std::cout << std::setprecision(4) << 123.456789 << std::endl;
    std::cout << std::setprecision(5) << 123.456789 << std::endl;
    std::cout << std::setprecision(6) << 123.456789 << std::endl;
    std::cout << std::setprecision(7) << 123.456789 << std::endl;
    std::cout << std::setprecision(8) << 123.456789 << std::endl;
    std::cout << std::setprecision(9) << 123.456789 << std::endl;

    std::cout << std::endl;
}
