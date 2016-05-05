// override.cpp

class Base {

  void func1();
  virtual void func2(float);
  virtual void func3() const;
  virtual long func4(int);

  virtual void f();

};

class Derived: public Base {

  virtual void func1() override;

  virtual void func2(double) override;

  virtual void func3() override;

  virtual int func4(int) override;

  void f() override;

};

int main(){

  Base base;
  Derived derived;

};
