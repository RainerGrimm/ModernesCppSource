// mathModuleTemplate1.ixx

module;

#include <iostream>
#include <typeinfo>
#include <utility>

export module math;   

template <typename T>
auto showType(T&& t) {
    return typeid(std::forward<T>(t)).name();
}

export namespace math {         

    template <typename T, typename T2>
    auto sum(T fir, T2 sec) {
        auto res = fir + sec;
        return std::make_pair(res, showType(res));
    }

}
