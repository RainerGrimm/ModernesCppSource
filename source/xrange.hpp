// xrange.hpp

#include <range/v3/all.hpp>

template <long long Begin, long long End>
auto xrange(int stepsize = 1) {
    if constexpr (Begin < End) {
        return ranges::views::iota(Begin, End) | ranges::views::stride(stepsize); 
    }
    else {
        long long end  = End + 1;
        long long begin = Begin + 1;
        stepsize *= -1;
        return ranges::views::iota(end, begin) | ranges::views::reverse 
                                               | ranges::views::stride(stepsize);
    }
}
