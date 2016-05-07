// sharedPtr.cpp

#include <iostream>
#include <memory>

using std::shared_ptr;

struct MyInt{
  MyInt(int v):val(v){
    std::cout << "  Hello: " << val << std::endl;
  }
  ~MyInt(){
    std::cout << "  Good Bye: " << val << std::endl;
  }
  int val;
};

int main(){

  std::cout << std::endl;

  shared_ptr<MyInt> sharPtr(new MyInt(1998));
  std::cout << "    My value: " << sharPtr->val << std::endl;
  std::cout << "sharedPtr.use_count(): " << sharPtr.use_count() << std::endl;


  {
    shared_ptr<MyInt> locSharPtr(sharPtr);
    std::cout << "locSharPtr.use_count(): " << locSharPtr.use_count() << std::endl;
  }
  std::cout << "sharPtr.use_count(): "<<  sharPtr.use_count() << std::endl;

  shared_ptr<MyInt> globSharPtr= sharPtr;
  std::cout << "sharPtr.use_count(): "<<  sharPtr.use_count() << std::endl;
  globSharPtr.reset();
  std::cout << "sharPtr.use_count(): "<<  sharPtr.use_count() << std::endl;

  sharPtr= shared_ptr<MyInt>(new MyInt(2011));

  std::cout << std::endl;
  
}
