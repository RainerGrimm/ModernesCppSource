// uniquePtrArray.cpp

#include <iomanip>
#include <iostream>
#include <memory>

class MyStruct{
public:
  MyStruct(){
    std::cout << std::setw(15) << std::left << (void*) this << " Hello "  << std::endl;
  }
  ~MyStruct(){
    std::cout << std::setw(15) << std::left << (void*)this << " Good Bye " << std::endl;
  }
};

int main(){
    
  std::cout << std::endl;
    
  std::unique_ptr<int> uniqInt(new int(2011));
  std::cout << "*uniqInt: " << *uniqInt << std::endl;

  std::cout << std::endl;

  {
    std::unique_ptr<MyStruct[]> myUniqueArray{new MyStruct[5]};
  }

  std::cout << std::endl;

  {
    std::unique_ptr<MyStruct[]> myUniqueArray{new MyStruct[1]};
    MyStruct myStruct;
    myUniqueArray[0]=myStruct;
  }

  std::cout << std::endl;

  {
    std::unique_ptr<MyStruct[]> myUniqueArray{new MyStruct[1]};
    MyStruct myStruct;
    myStruct= myUniqueArray[0];
  }

  std::cout << std::endl;

}
