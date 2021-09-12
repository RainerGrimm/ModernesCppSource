// mathInterfaceUnit3.ixx

module;                   

#include <numeric>
#include <vector>

export module math;       

export namespace math {

   int add(int fir, int sec);

   int getProduct(const std::vector<int>& vec);

}

module :private;

int add(int fir, int sec) {
    return fir + sec;
}

int getProduct(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
}