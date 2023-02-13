// strategizedLockingRuntime.cpp

#include <iostream>
#include <mutex>
#include <shared_mutex>

class Lock {
public:
    virtual void lock() const = 0;
    virtual void unlock() const = 0;
};

class StrategizedLocking {
    Lock& lock;
public:
    StrategizedLocking(Lock& l): lock(l){
        lock.lock();
    }
    ~StrategizedLocking(){
        lock.unlock();
    }
};

struct NullObjectMutex{
    void lock(){}
    void unlock(){}
};

class NoLock : public Lock {
    void lock() const override {
        std::cout << "NoLock::lock: " << '\n';
        nullObjectMutex.lock();
    }
    void unlock() const override {
        std::cout << "NoLock::unlock: " << '\n';
         nullObjectMutex.unlock();
    }
    mutable NullObjectMutex nullObjectMutex;
};

class ExclusiveLock : public Lock {
    void lock() const override {
        std::cout << "    ExclusiveLock::lock: " << '\n';
        mutex.lock();
    }
    void unlock() const override {
        std::cout << "    ExclusiveLock::unlock: " << '\n';
        mutex.unlock();
    }
    mutable std::mutex mutex;
};

class SharedLock : public Lock {
    void lock() const override {
        std::cout << "        SharedLock::lock_shared: " << '\n';
        sharedMutex.lock_shared();
    }
    void unlock() const override {
        std::cout << "        SharedLock::unlock_shared: " << '\n';
        sharedMutex.unlock_shared();
    }
    mutable std::shared_mutex sharedMutex;
};

int main() {
    
    std::cout << '\n';
    
    NoLock noLock;
    StrategizedLocking stratLock1{noLock};
    
    {
        ExclusiveLock exLock;
        StrategizedLocking stratLock2{exLock};
        {
            SharedLock sharLock;
            StrategizedLocking startLock3{sharLock};
        }
    }
    
    std::cout << '\n';
    
}
