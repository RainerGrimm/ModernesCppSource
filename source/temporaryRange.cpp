// temporaryRange.cpp

#include <initializer_list>
#include <ranges>


int main() {

    const auto numbers = {1, 2, 3, 4, 5};

    auto firstThree = numbers | std::views::drop(3);
    // auto firstThree = {1, 2, 3, 4, 5} | std::views::drop(3); ERROR

    std::ranges::drop_view firstFour{numbers, 4};
   // std::ranges::drop_view firstFour{{1, 2, 3, 4, 5}, 4}; ERROR
   
}