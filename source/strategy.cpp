// strategy.cpp

#include <iostream>
#include <memory>
#include <utility>

class Strategy {
public:
    virtual void execute() = 0;
    virtual ~Strategy() {}
};

class Context {
    std::unique_ptr<Strategy> strat{};
public:
    void setStrategy(std::unique_ptr<Strategy> strat_)  { strat = std::move(strat_); }
    void strategy()  { if (strat) strat->execute(); }
};

class Strategy1 : public Strategy {
public:
    void execute() { std::cout << "Strategy1 executed\n"; }
};

class Strategy2 : public Strategy {
public:
    void execute() { std::cout << "Strategy2 executed\n"; }
};

class Strategy3 : public Strategy {
public:
    void execute() { std::cout << "Strategy3 executed\n"; }
};

int main() {

    std::cout << '\n';

    Context k;

    k.setStrategy(std::make_unique<Strategy1>());
    k.strategy();

    k.setStrategy(std::make_unique<Strategy2>());
    k.strategy();

    k.setStrategy(std::make_unique<Strategy3>());
    k.strategy();

    std::cout << '\n';

}
