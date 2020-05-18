// math1.ixx
module;                   // (1)

#include <numeric>
#include <vector>

export module math;       // (2)

export int add(int fir, int sec){
    return fir + sec;
}

export int getProduct(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
}