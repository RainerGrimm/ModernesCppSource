// Program2.cpp

#include <iostream>
namespace details
{
    template <typename B>
    std::true_type test_pre_ptr_convertible(const volatile B *);
    template <typename>
    std::false_type test_pre_ptr_convertible(const volatile void *);
}
template <typename Base, typename Derived>
struct is_base_of : std::integral_constant<
                        bool,
                        std::is_class<Base>::value && std::is_class<Derived>::value &&
                             decltype(details::test_pre_ptr_convertible<Base>
                             (static_cast<Derived *>(nullptr)))::value
                        > { };
struct Base {};
struct Derived : public Base {};
struct A {};
int main()
{
    std::cout << std::boolalpha;
    std::cout << "Base is base of Derived: "
              << is_base_of<Base, Derived>::value << "\n";
    std::cout << "Derived is base of Base: "
              << is_base_of<Derived, Base>::value << "\n";
    std::cout << "Base is base of A: "
              << is_base_of<Base, A>::value << "\n";
    std::cout << "Base is base of Base: "
              << is_base_of<Base, Base>::value << "\n";
    std::cout << "Base is base of const Derived: "
              << is_base_of<Base, const Derived>::value << "\n";
    std::cout << "int is base of int: "
              << is_base_of<int, int>::value << "\n";
    std::cout << "void is base of void: "
              << is_base_of<void, void>::value << "\n";
    std::cout << "void is base of Base: " < < is_base_of<void, Base>::value << "\n";
    return 0;
}