// refVersusCopySharedPtr.cpp

#include <memory>
#include <iostream>

void byReference(std::shared_ptr<int>& refPtr){
  std::cout << "refPtr.use_count(): " << refPtr.use_count() << std::endl;
}

void byCopy(std::shared_ptr<int> cpyPtr){
  std::cout << "cpyPtr.use_count(): " << cpyPtr.use_count() << std::endl;
}


int main(){

    std::cout <<  std::endl;

    auto shrPtr= std::make_shared<int>(2011);

    std::cout << "shrPtr.use_count(): " << shrPtr.use_count() << std::endl;

    byReference(shrPtr);
    byCopy(shrPtr);
    
    std::cout << "shrPtr.use_count(): " << shrPtr.use_count() << std::endl;
    
    std::cout << std::endl;
    
}