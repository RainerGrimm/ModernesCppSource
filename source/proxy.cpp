#include <iostream>
#include <memory>

class MyInt{
 public:
    MyInt(int i):i_(i){}
    int getValue() const {
        return i_;
    }
 private:
    int i_;
};

int main(){

    std::cout << '\n';

    MyInt* myInt = new MyInt(1998);
    std::cout << "myInt->getValue(): " << myInt->getValue() << '\n';

    std::unique_ptr<MyInt> uniquePtr{new MyInt(1998)};
    std::cout << "uniquePtr->getValue(): " << uniquePtr->getValue() << '\n';

    std::shared_ptr<MyInt> sharedPtr{new MyInt(1998)};
    std::cout << "sharedPtr->getValue(): " << sharedPtr->getValue() << '\n';

    std::cout << '\n';

}