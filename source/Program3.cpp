// Program3.cpp

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
                        std::is_class<Base>::value && std::is_class<Derived>::value &&decltype(details::test_pre_ptr_convertible<Base>(static_cast<Derived *>(nullptr)))::value>
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
    // error: ‘Base’ is an ambiguous base of ‘Multi’
    std::cout << "Base is base of Multi: "
              << is_base_of<Base, Multi>::value << "\n";
    return 0;
}