// MyClass.h

#include <typeinfo>
#include <string>

template <typename T>
class MyClass{
 public:
    MyClass(T t) { }
    std::string getType() const;
};

