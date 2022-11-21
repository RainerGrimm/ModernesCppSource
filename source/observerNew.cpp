#include <iostream>
#include <list>
#include <string>

class Observer {
 public:
  virtual ~Observer(){};
  virtual void notify() = 0;
};

class Subject {
 public:
  void registerObserver(Observer* observer) {
    observers.push_back(observer);
  }
  void unregisterObserver(Observer* observer) {
    observers.remove(observer);
  }
  void notifyObservers() {
    for (auto observer: observers) observer->notify();
  }

 private:
  std::list<Observer *> observers;
};

class ConcreteObserverA : public Observer {
 public:
    ConcreteObserverA(Subject& subject) : subject_(subject) {
        this->subject_.registerObserver(this);
    }
    void notify() override {
        std::cout << "ConcreteObserverA::notify\n";
    }
 private: 
    Subject& subject_;
};

class ConcreteObserverB : public Observer {
 public:
    ConcreteObserverB(Subject& subject) : subject_(subject) {
        this->subject_.registerObserver(this);
    }
    void notify() override {
        std::cout << "ConcreteObserverB::notify\n";
    }
 private: 
    Subject& subject_;
};


int main() {

    Subject* subject = new Subject;
    Observer* observerA = new ConcreteObserverA(*subject);
    Observer* observerB = new ConcreteObserverB(*subject);

    subject->notifyObservers();
    std::cout <<  "    subject->unregisterObserver(observerA)" << "\n";
    subject->unregisterObserver(observerA);
    subject->notifyObservers();

    delete observerA;
    delete observerB;

    delete subject;

}