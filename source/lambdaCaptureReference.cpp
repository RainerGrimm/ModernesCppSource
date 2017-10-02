// lambdaCaptureReference.cpp

#include <functional>
#include <iostream>

std::function<int(int)> makeLambda(int a){
    int local = 2 * a;
    auto lam = [&local](int b){ return local + b; };           // 1
    std::cout << "lam(5): "<<  lam(5) << std::endl;            // 2
    return lam;
}

int main(){
  
  std::cout << std::endl;
  
  int local = 10;
    
  auto addLocal = [&local](int b){ return local + b; };       // 3
    
  auto add10 = makeLambda(5);
    
  std::cout << "addLocal(5): " << addLocal(5) << std::endl;    // 4
  std::cout << "add10(5): " << add10(5) << std::endl;          // 5
  
  std::cout << std::endl;
    
}
