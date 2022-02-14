// fibonacciConstexprIf.cpp

template<int N>
constexpr int fibonacci()
{
    if constexpr (N>=2)
        return fibonacci<N-1>() + fibonacci<N-2>();
    else
        return N;
}

template <int N>                                                  // (1)            
struct Fibonacci{
    static int const value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

template <>                                                      // (2)                
struct Fibonacci<1>{
    static int const value = 1;
};

template <>                                                      // (3)                
struct Fibonacci<0>{
    static int const value = 0;
};

int main() {

    static_assert(fibonacci<7>() == 13);
    static_assert(fibonacci<7>() == Fibonacci<7>::value);
    
}