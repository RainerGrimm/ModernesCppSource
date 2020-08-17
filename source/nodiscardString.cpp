// nodiscardString.cpp

#include <utility>

struct MyType {

     [[nodiscard("Implicit destroying of temporary MyInt.")]] MyType(int, bool) {}

};

template <typename T, typename ... Args>
[[nodiscard("You have a memory leak.")]]
T* create(Args&& ... args){
  return new T(std::forward<Args>(args)...);
}

enum class [[nodiscard("Don't ignore the error code.")]] ErrorCode {
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
    

    
