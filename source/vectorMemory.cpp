// vectorMemory.cpp

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void showInfo(const T& t,const std::string& name){

  std::cout << name << " t.size(): " << t.size() << std::endl;
  std::cout << name << " t.capacity(): " << t.capacity() << std::endl;

}

int main(){
    
    std::cout << std::endl;

    std::vector<int> vec;                                            // (1)

    std::cout << "Maximal size: " << std::endl;
    std::cout << "vec.max_size(): " << vec.max_size() << std::endl;  // (2)
    std::cout << std::endl;

    std::cout << "Empty vector: " << std::endl;
    showInfo(vec, "Vector");
    std::cout << std::endl;

    std::cout << "Initialised with five values: " << std::endl;   
    vec = {1,2,3,4,5};
    showInfo(vec, "Vector");                                        // (3)
    std::cout << std::endl;

    std::cout << "Added four additional values: " << std::endl;
    vec.insert(vec.end(),{6,7,8,9});
    showInfo(vec,"Vector");                                         // (4)
    std::cout << std::endl;

    std::cout << "Resized to 30 values: " << std::endl;
    vec.resize(30);
    showInfo(vec,"Vector");                                         // (5)
    std::cout << std::endl;

    std::cout << "Reserved space for at least 1000 values: " << std::endl;
    vec.reserve(1000);
    showInfo(vec,"Vector");                                        // (6)
    std::cout << std::endl;

    std::cout << "Shrinke to the current size: " << std::endl;
    vec.shrink_to_fit();                                           // (7)
    showInfo(vec,"Vector");

}
