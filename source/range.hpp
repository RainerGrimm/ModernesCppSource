// range.hpp

#include <range/v3/all.hpp>
#include <vector>
#include <utility>

std::vector<int> range(int begin, int end, int stepsize = 1) {
    std::vector<int> result{};
    if (begin < end) {
        for (int i: ranges::views::iota(begin, end) | ranges::views::stride(stepsize)) {
            result.push_back(i);
        }
    }
    else {
        begin++;
        end++;
        stepsize *= -1;
        for (int i: ranges::views::iota(end, begin) | ranges::views::reverse 
                                             | ranges::views::stride(stepsize)) {
            result.push_back(i);
        }
    }
    return result;
}
