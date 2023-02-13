// strategizedLockingCompileTimeWithConcepts.cpp

#include <iostream>
#include <mutex>
#include <shared_mutex>

template <typename T>
concept BasicLockable = requires(T lo) {
    lo.lock();
    lo.unlock();
};
    
template <BasicLockable Lock>
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

struct NullObjectMutex {
    void lock(){}
    void unlock(){}
};

class NoLock{
public:
    void lock() const {
        std::cout << "NoLock::lock: " << '\n';
        nullObjectMutex.lock();
    }
    void unlock() const {
        std::cout << "NoLock::unlock: " << '\n';
         nullObjectMutex.lock();
    }
    mutable NullObjectMutex nullObjectMutex;
};

class ExclusiveLock {
public:
    void lock() const {
        std::cout << "    ExclusiveLock::lock: " << '\n';
        mutex.lock();
    }
    void unlock() const {
        std::cout << "    ExclusiveLock::unlock: " << '\n';
        mutex.unlock();
    }
    mutable std::mutex mutex;
};

class SharedLock {
public:
    void lock() const {
        std::cout << "        SharedLock::lock_shared: " << '\n';
        sharedMutex.lock_shared();
    }
    void unlock() const {
        std::cout << "        SharedLock::unlock_shared: " << '\n';
        sharedMutex.unlock_shared();
    }
    mutable std::shared_mutex sharedMutex;
};

int main() {

    std::cout << '\n';
    
    NoLock noLock;
    StrategizedLocking<NoLock> stratLock1{noLock};
    
    {
        ExclusiveLock exLock;
        StrategizedLocking<ExclusiveLock> stratLock2{exLock};
        {
            SharedLock sharLock;
            StrategizedLocking<SharedLock> startLock3{sharLock};
        }
    }
    
    std::cout << '\n';

}