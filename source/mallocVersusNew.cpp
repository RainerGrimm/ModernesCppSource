// mallocVersusNew.cpp

#include <iostream>
#include <string>

struct Record{
  Record(std::string na = "Record"): name(na){}                 // (5)
  std::string name;
};

int main(){
    
    std::cout << std::endl;
    
    Record* p1 = static_cast<Record*>(malloc(sizeof(Record)));  // (1)
    std::cout << p1->name << std::endl;                         // (3)

    auto p2 = new Record;                                       // (2)
    std::cout << p2->name << std::endl;                         // (4)  
    
    std::cout << std::endl;
   
}
