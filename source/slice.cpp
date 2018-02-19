// slice.cpp

struct Base { 
  int base{1998};
}
 
struct Derived : Base { 
  int derived{2011};
}

void needB(Base b){
    // ...
}
 
int main(){

  Derived d;
  Base b = d;              // (1)
  Base b2(d);              // (2)
  needB(d);                // (3)

}
