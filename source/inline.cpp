// inline.cpp

class MyClass{
public:
  void implicitInline(){};
  void explicitInline();
  inline void notInline();
};

inline void MyClass::explicitInline(){}
void MyClass::notInline(){}

int main(){

  MyClass cl;
  cl.implicitInline();
  cl.explicitInline();
  cl.notInline();

}


  