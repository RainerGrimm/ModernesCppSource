// badCast.cpp

struct A{
    virtual void f() {}
};
struct B : A {};

int main(){
    
    A a;
    B b;

    B* b1 = dynamic_cast<B*>(&a);  // nullptr, because 'a' is not a 'B'
    B& b2 = dynamic_cast<B&>(a);   // std::bad_cast, because 'a' is not a 'B' 
   
}
