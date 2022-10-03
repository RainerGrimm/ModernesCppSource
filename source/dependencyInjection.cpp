// dependencyInjection.cpp

#include <chrono>
#include <iostream>
#include <memory>

class Logger {
public:
    virtual void write(const std::string&) const = 0;
    virtual ~Logger() = default;
};

class SimpleLogger: public Logger {
    void write(const std::string& mess) const override {
        std::cout << mess << '\n';
    }
};

class TimeLogger: public Logger {
    typedef std::chrono::duration<long double> MySecondTick;
    long double timeSinceEpoch() const {
        auto timeNow = std::chrono::system_clock::now();
        auto duration = timeNow.time_since_epoch();
        MySecondTick sec(duration);
        return sec.count();
    }
    void write(const std::string& mess) const override {
        std::cout << std::fixed;
        std::cout << "Time since epoch: " << timeSinceEpoch() << ": " << mess << '\n';
    }

};

class Client {
public:
    Client(std::shared_ptr<Logger> log): logger(log) {}   // (1)
    void doSomething() {
        logger->write("Message");
    }
    void setLogger(std::shared_ptr<Logger> log) {         // (2)
        logger = log;
    }
private:
    std::shared_ptr<Logger> logger;
};
        

int main() {
    
    std::cout << '\n';
    
    Client cl(std::make_shared<SimpleLogger>());
    cl.doSomething();
    cl.setLogger(std::make_shared<TimeLogger>());
    cl.doSomething();
    cl.doSomething();
    
    std::cout << '\n';
 
}