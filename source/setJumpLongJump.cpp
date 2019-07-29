// setJumpLongJump.cpp

#include <cstdlib>
#include <iostream>
#include <csetjmp>
#include <string>

class ResourceGuard{
  private:
    const std::string resource;
  public:
    ResourceGuard(const std::string& res):resource(res){
      std::cout << "Acquire the " << resource << "." <<  std::endl;
    }
    ~ResourceGuard(){
      std::cout << "Release the "<< resource << "." << std::endl;
    }
};

int main(){

  std::cout << std::endl;
  
  std::jmp_buf env;
  volatile int val;
  
  val = setjmp(env);                                  // (1)
  
  if (val){
      std::cout << "val: " <<  val << std::endl;
      std::exit(EXIT_FAILURE);
  }
  
  {
    ResourceGuard resGuard3{"memoryBlock3"};           // (2)
    std::longjmp(env, EXIT_FAILURE);                   // (3)
  }                                                    // (4)

}
