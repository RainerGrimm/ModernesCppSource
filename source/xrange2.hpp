#include <stdio.h>
#include <range/v3/all.hpp>
 
namespace view = ranges::views;

auto xrange(long long begin, long long end, long long step = 1) {
    if(step == 0) {
        throw std::invalid_argument("Step cannot be 0");
    }
    auto Step = begin < end ? step : -step;
    auto Begin = std::min(begin, end);
    auto End = Step < 0 ? Begin : std::max(begin, end);
    return view::iota(Begin, End)
    | view::stride(std::abs(Step))
    | view::transform([begin, end](std::size_t i){
        return begin < end ? i : end - (i - begin);
    });
}

auto xrange(long long end) {
    return xrange(0, end, 1);
}
