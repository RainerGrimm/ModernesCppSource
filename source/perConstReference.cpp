// perConstReference.cpp

#include <thread>

class NonCopyableClass{
    public:

    // the compiler generated default constructor
    NonCopyableClass() = default;

    // disallow copying
    NonCopyableClass& operator = (const NonCopyableClass&) = delete;
    NonCopyableClass (const NonCopyableClass&) = delete;
  
};

void perConstReference(const NonCopyableClass& nonCopy){}

int main(){

    NonCopyableClass nonCopy;

    perConstReference(nonCopy);
    
    std::thread t(perConstReference, nonCopy);
    t.join();

}
