// singleDispatch.cpp

#include <iostream>

class Ball {
 public:
    virtual std::string getName() const = 0;
};

class HandBall: public Ball {
    std::string getName() const override {
        return "HandBall";
    }
};

int main() {

    std::cout << '\n';

    HandBall hBall;

    Ball* ballPointer = &hBall;
    std::cout << "ballPointer->getName(): " << ballPointer->getName() << '\n';

    Ball& ballReference = hBall;
    std::cout << "ballReference.getName(): " << ballReference.getName() << '\n';

    std::cout << '\n';

}