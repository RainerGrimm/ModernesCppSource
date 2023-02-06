// equalityReferenceValue.cpp

#include <iostream>

class Date{
 public:
    Date(int y, int m, int d): year(y), month(m), day(d){}
    bool operator==(const Date&) const = default;
 private:
    int year;
    int month;
    int day;
};

class Man{
 public:
    Man(const std::string n, int a): name(n), age(a){}
    bool operator==(const Man&) const = default;
 private:
    std::string name;
    int age;
};

int main() {

    std::cout << std::boolalpha << '\n';

    Date date1(2022, 10, 31);
    Date date2(2022, 10, 31);

    std::cout << "date1 == date2: " << (date1 == date2) << '\n';
    std::cout << "date1 != date2: " << (date1 != date2) << '\n';

    std::cout << '\n';

    Man man1("Rainer Grimm", 56);
    Man man2("Rainer Grimm", 56);

    std::cout << "man1 == man2: " << (man1 == man2) << '\n';
    std::cout << "man1 != man2: " << (man1 != man2) << '\n';

    std::cout << '\n';

}