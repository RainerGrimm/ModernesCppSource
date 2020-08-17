// nodiscard.cpp

#include <utility>

struct MyType {

     MyType(int, bool) {}

};

template <typename T, typename ... Args>
[[nodiscard]]
T* create(Args&& ... args){
  return new T(std::forward<Args>(args)...);
}

enum class [[nodiscard]] ErrorCode {
    Okay,
    Warning,
    Critical,
    Fatal
};

ErrorCode errorProneFunction() { return ErrorCode::Fatal; }

int main() {

    int* val = create<int>(5);
    delete val;

    create<int>(5);         // (1)

    errorProneFunction();   // (2)
    
    MyType(5, true);        // (3)

}
    

    
