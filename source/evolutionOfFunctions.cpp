// evolutionOfFunctions.cpp

#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::string addMe(std::string fir, std::string sec){
  return fir + " " + sec;
};

struct AddMe{
  
  AddMe()= default;
  AddMe(std::string gl): glue(gl) {}
  
  std::string operator()(std::string fir, std::string sec) const {
    return fir + glue + sec;
  }
  
  std::string glue= " ";
  
};

int main(){
  
  std::vector<std::string> myStrings={"The", "evolution", "of", "the", "function", "concept", "in", "C++."};
  
  std::string fromFunc= std::accumulate(myStrings.begin(), myStrings.end(), std::string{}, addMe);
  
  std::cout << fromFunc << std::endl;
  
  std::cout << std::endl;
  
  std::string fromFuncObj= std::accumulate(myStrings.begin(), myStrings.end(), std::string{}, AddMe());
  
  std::cout << fromFuncObj << std::endl;
  
  std::string fromFuncObj2= std::accumulate(myStrings.begin(), myStrings.end(), std::string{}, AddMe(":"));
  
  std::cout << fromFuncObj2 << std::endl;
  
  std::cout << std::endl;
  
  std::string fromLambdaFunc= std::accumulate(myStrings.begin(), myStrings.end(), std::string{}, [](std::string fir, std::string sec){ return fir + " " + sec; });
  
  std::cout << fromLambdaFunc << std::endl;
  
  std::string glue=":";
  
  auto lambdaFunc= [glue](std::string fir, std::string sec){ return fir + glue + sec; };
  
  std::string fromLambdaFunc2=  std::accumulate(myStrings.begin(), myStrings.end(), std::string{}, lambdaFunc);
  
  std::cout << fromLambdaFunc2 << std::endl;
  
  std::cout << std::endl;
  
  std::string fromLambdaFuncGeneric= std::accumulate(myStrings.begin(), myStrings.end(), std::string{}, [glue](auto fir, auto sec){ return fir + glue + sec; });
  
  std::cout << fromLambdaFuncGeneric << std::endl;
  
  auto lambdaFuncGeneric= [](auto fir, auto sec){ return fir + sec; };
  
  auto fromLambdaFuncGeneric1= std::accumulate(myStrings.begin(), myStrings.end(), std::string{}, lambdaFuncGeneric);
  
  std::cout << fromLambdaFuncGeneric1 << std::endl;
  
  std::vector<int> myInts={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  auto fromLambdaFuncGeneric2= std::accumulate(myInts.begin(), myInts.end(), int{}, lambdaFuncGeneric);
  
  std::cout << fromLambdaFuncGeneric2 << std::endl;
  
}