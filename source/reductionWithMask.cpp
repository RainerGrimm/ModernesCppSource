// reductionWithMask.cpp

#include <cassert>
#include <experimental/simd>
 
namespace stq = std::experimental;
 
int main()
{
    using mask = stq::fixed_size_simd_mask<int, 4>;
 
    mask mask1{false}; // = {0, 0, 0, 0}
    assert
    (
        stq::none_of(mask1) == true &&
        stq::any_of(mask1) == false &&
        stq::some_of(mask1) == false &&
        stq::all_of(mask1) == false
    );
 
    mask mask2{true}; // = {1, 1, 1, 1}
    assert
    (
        stq::none_of(mask2) == false &&
        stq::any_of(mask2) == true &&
        stq::some_of(mask2) == false &&
        stq::all_of(mask2) == true
    );
 
    mask mask3{true};
    mask3[0] = mask3[1] = false; // mask3 = {0, 0, 1, 1}
    assert
    (
        stq::none_of(mask3) == false &&
        stq::any_of(mask3) == true &&
        stq::some_of(mask3) == true &&
        stq::all_of(mask3) == false
    );
}