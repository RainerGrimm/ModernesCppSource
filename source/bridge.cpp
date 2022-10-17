// bridget.cpp

#include <iostream>

class Implementor {                           // (1)
public:
    virtual void implementation() const = 0;

    virtual ~Implementor() = default;
};
 
class ImplementorA: public Implementor {
public:
    ImplementorA() = default;
 
    void implementation() const {
        std::cout << "ImplementatorA::implementation" << '\n';
    }
};
 
class ImplementorB: public Implementor {
public:
    ImplementorB() = default;

    void implementation() const {
        std::cout << "ImplementatorB::implementation" << '\n';
    }
};

class Abstraction {                           // (2)      
public:
    virtual void function() const = 0;
    virtual ~Abstraction() = default;
};

class RefinedAbstraction: public Abstraction {
public:
    RefinedAbstraction(Implementor& impl) : 
		implementor(impl) {
    }
 
    void function() const {
        std::cout << "RefinedAbstraction::function\n";
        implementor.implementation();
    }
private:
    Implementor& implementor;
};
 
int main() {

    std::cout << '\n';

    ImplementorA implementorA;
    ImplementorB implementorB;
 
    RefinedAbstraction refinedAbstraction1(implementorA);  // (3)
    RefinedAbstraction refinedAbstraction2(implementorB);  // (4)

    Abstraction *abstraction1 = &refinedAbstraction1;
    Abstraction *abstraction2 = &refinedAbstraction2;

    abstraction1->function();

    std::cout << '\n';

    abstraction2->function();

    std::cout << '\n';

}