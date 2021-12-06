// Program5.cpp

#include <iostream>
namespace details
{
    template <typename B>
    std::true_type test_pre_ptr_convertible(const volatile B *);
    template <typename>
    std::false_type test_pre_ptr_convertible(const volatile void *);
    template <typename, typename>
    auto test_pre_is_base_of(...) -> std::true_type;
    template <typename B, typename D>
    auto test_pre_is_base_of(int) -> decltype(test_pre_ptr_convertible<B>(static_cast<D *>(nullptr)));
}
// A standard conversion sequence is always better
// than a user-defined conversion sequence
// or an ellipsis conversion sequence.
// https://en.cppreference.com/w/cpp/language/overload_resolution
template <typename Base, typename Derived>
struct is_base_of : std::integral_constant<
                        bool,
                        std::is_class<Base>::value && std::is_class<Derived>::value &&decltype(details::test_pre_is_base_of<Base, Derived>(0))::value>
{
};
struct Base
{
};
struct Derived1 : public Base
{
};
struct Derived2 : public Base
{
};
struct Multi : public Derived1, public Derived2
{
};
int main()
{
    std::cout << std::boolalpha;
    std::cout << "Base is base of Derived1: "
              << is_base_of<Base, Derived1>::value << "\n";
    std::cout << "Derived1 is base of Base: "
              << is_base_of<Derived1, Base>::value << "\n";
    std::cout << "Base is base of Derived2: "
              << is_base_of<Base, Derived2>::value << "\n";
    std::cout << "Derived2 is base of Base: "
              << is_base_of<Derived2, Base>::value << "\n";
    std::cout << "Derived1 is base of Multi: "
              << is_base_of<Derived1, Multi>::value << "\n";
    std::cout << "Derived2 is base of Multi: "
              << is_base_of<Derived2, Multi>::value << "\n";
    std::cout << "Base is base of Multi: "
              << is_base_of<Base, Multi>::value << "\n";
    return 0;
}