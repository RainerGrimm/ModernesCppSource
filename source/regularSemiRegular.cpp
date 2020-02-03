// regularSemiRegular.cpp

#include <concepts>
#include <vector>
#include <utility>

template<typename T>
struct isSemiRegular: std::integral_constant<bool,
                                      std::is_default_constructible<T>::value &&
                                      std::is_copy_constructible<T>::value &&
                                      std::is_copy_assignable<T>::value &&
                                      std::is_move_constructible<T>::value &&
                                      std::is_move_assignable<T>::value &&
                                      std::is_destructible<T>::value &&
                                      std::is_swappable<T>::value >{};


template<typename T>
concept SemiRegular = isSemiRegular<T>::value;

template<typename T>
concept Equal =
    requires(T a, T b) {
        { a == b } -> std::convertible_to<bool>;
        { a != b } -> std::convertible_to<bool>;
};

template<typename T>                              
concept Regular = Equal<T> && 
                  SemiRegular<T>;

template <Regular T>                              
void behavesLikeAnInt(T) {
    // ...
}

template <std::regular T>                         
void behavesLikeAnInt2(T) {
    // ...
}

struct EqualityComparable { };                                                           
bool operator == (EqualityComparable const&, EqualityComparable const&) { return true; }

struct NotEqualityComparable { };                 

int main() {

    int myInt{};
    behavesLikeAnInt(myInt);
    behavesLikeAnInt2(myInt);

    std::vector<int> myVec{};
    behavesLikeAnInt(myVec);
    behavesLikeAnInt2(myVec);

    EqualityComparable equComp;
    behavesLikeAnInt(equComp);
    behavesLikeAnInt2(equComp);

    NotEqualityComparable notEquComp;              
    behavesLikeAnInt(notEquComp);                  
    behavesLikeAnInt2(notEquComp);                
    
}
