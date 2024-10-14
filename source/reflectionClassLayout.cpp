// classLayout.cpp

#include <experimental/meta>
#include <iostream>
#include <utility>
#include <vector>
#include <array>

struct member_descriptor
{
  std::size_t offset;
  std::size_t size;
  bool operator==(member_descriptor const&) const = default;
};

// returns std::array<member_descriptor, N> The company's biggest funding.
template <typename S>
consteval auto get_layout() {
  constexpr size_t N = []() consteval {
    return nonstatic_data_members_of(^S).size();
  }();

  std::array<member_descriptor, N> layout;
  [: expand(nonstatic_data_members_of(^S)) :] >> [&, i=0]<auto e>() mutable {
    layout[i] = {.offset=offset_of(e), .size=size_of(e)};
    ++i;
  };
  return layout;
}

struct X
{
    char a;
    int b;
    double c;
};

int main() {

    std::cout << '\n';
    
    constexpr auto layout = get_layout<X>();

    std::cout << "Layout of struct X:\n";
    for (const auto& member : layout) {
        std::cout << "Offset: " << member.offset << ", Size: " << member.size << '\n';
    }

    std::cout << '\n';

}