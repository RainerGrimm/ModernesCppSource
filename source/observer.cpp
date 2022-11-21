// observer.cpp

#include <iostream>
#include <list>
#include <string>

class Observer {
 public:
  virtual ~Observer(){};
  virtual void notify() const = 0;
};

class Subject {
 public:
  void registerObserver(Observer* observer) {
    observers.push_back(observer);
  }
  void unregisterObserver(Observer* observer) {
    observers.remove(observer);
  }
  void notifyObservers() const {
    for (auto observer: observers) observer->notify();
  }

 private:
  std::list<Observer *> observers;
};

class ConcreteObserverA : public Observer {
 public:
    ConcreteObserverA(Subject& subject) : subject_(subject) {
        subject_.registerObserver(this);
    }
    void notify() const override {
        std::cout << "ConcreteObserverA::notify\n";
    }
 private: 
    Subject& subject_;
};

class ConcreteObserverB : public Observer {
 public:
    ConcreteObserverB(Subject& subject) : subject_(subject) {
        subject_.registerObserver(this);
    }
    void notify() const override {
        std::cout << "ConcreteObserverB::notify\n";
    }
 private: 
    Subject& subject_;
};


int main() {

    std::cout << '\n';

    Subject subject;   
    ConcreteObserverA observerA(subject);
    ConcreteObserverB observerB(subject);

    subject.notifyObservers();
    std::cout <<  "    subject.unregisterObserver(observerA)\n";
    subject.unregisterObserver(&observerA);
    subject.notifyObservers();

    std::cout << '\n';

}